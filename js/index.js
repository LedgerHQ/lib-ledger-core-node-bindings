const crypto = require('crypto')
const path = require('path')
const axios = require('axios')
const fs = require('fs')

const binding = require('bindings')('ledger-core-node')

const MAX_RANDOM = 2684869021

const signTransaction = require('./signTransaction')
const { stringToBytesArray, bytesToHex, hexToBytes, bytesArrayToString } = require('./helpers')

// export all helpers for convenience
exports.helpers = require('./helpers')

//                     ----------------------------------
//                     NJSExecutionContext Implementation
//                     ----------------------------------

const NJSExecutionContextImpl = {
  execute: runnable => {
    try {
      runnable.run()
    } catch (e) {
      console.log(e)
    }
  },
  delay: (runnable, ms) => setTimeout(() => runnable.run(), ms),
}

//                      -------------------------------
//                      ThreadDispatcher Implementation
//                      -------------------------------

const NJSThreadDispatcherImpl = {
  contexts: {},
}

/**
 * @param: name: string, context's name
 * @return: NJSExecutionContext
 */
NJSThreadDispatcherImpl.getThreadPoolExecutionContext = name =>
  NJSThreadDispatcherImpl.getSerialExecutionContext(name)

/**
 * @return: NJSExecutionContext
 */
NJSThreadDispatcherImpl.getMainExecutionContext = () =>
  NJSThreadDispatcherImpl.getSerialExecutionContext('main')

/**
 * @param: name: string, context's name
 * @return: NJSExecutionContext
 */
NJSThreadDispatcherImpl.getSerialExecutionContext = name => {
  let currentContext = NJSThreadDispatcherImpl.contexts[name]
  if (currentContext === undefined) {
    currentContext = new binding.NJSExecutionContext(NJSExecutionContextImpl)
    NJSThreadDispatcherImpl.contexts[name] = currentContext
  }
  return currentContext
}

/**
 * @return: NJSLock
 */
NJSThreadDispatcherImpl.newLock = () => {
  console.log('Not implemented') // eslint-disable-line no-console
}

const NJSThreadDispatcher = new binding.NJSThreadDispatcher(NJSThreadDispatcherImpl)

//                         -------------------------
//                         HttpClient Implementation
//                         -------------------------

const METHODS = {
  0: 'GET',
  1: 'POST',
  2: 'PUT',
  3: 'DELETE',
}

const EVENT_CODE = {
  UNDEFINED: 0,
  NEW_OPERATION: 1,
  NEW_BLOCK: 2,
  SYNCHRONIZATION_STARTED: 3,
  SYNCHRONIZATION_FAILED: 4,
  SYNCHRONIZATION_SUCCEED: 5,
  SYNCHRONIZATION_SUCCEED_ON_PREVIOUSLY_EMPTY_ACCOUNT: 6,
}

const SIGHASH_TYPES = {
  SIGHASH_ALL: 1,
  SIGHASH_NONE: 2,
  SIGHASH_SINGLE: 3,
  SIGHASH_FORKID: 0x40,
  SIGHASH_ANYONECANPAY: 0x80,
}

const TIME_PERIODS = {
  DAY: 0,
  WEEK: 1,
  MONTH: 2,
}

const OPERATION_TYPES = {
  SEND: 0,
  RECEIVE: 1,
}

let httpQueryImplementation = async arg => {
  try {
    const res = await axios(arg)
    return res
  } catch (err) {
    let strErr = ''
    // handle axios err
    if (err.response && err.response.data && err.response.data.error) {
      strErr = err.response.data.error
    } else {
      strErr = 'something went wrong'
    }
    throw new Error(strErr)
  }
}

exports.setHttpQueryImplementation = axiosLikeFunction => {
  httpQueryImplementation = axiosLikeFunction
}

const NJSHttpClientImpl = {
  execute: async r => {
    const method = r.getMethod()
    const headersMap = r.getHeaders()
    let data = r.getBody()
    if (Array.isArray(data)) {
      const dataStr = bytesArrayToString(data)
      try {
        data = JSON.parse(dataStr)
      } catch (err) {}
    }
    const url = r.getUrl()
    const headers = {}
    headersMap.forEach((v, k) => {
      headers[k] = v
    })
    let res
    try {
      res = await axios({ method: METHODS[method], url, headers, data })
      const urlConnection = createHttpConnection(res)
      r.complete(urlConnection, null)
    } catch (err) {
      const urlConnection = createHttpConnection(res, err.message)
      r.complete(urlConnection, { code: 0, message: err.message })
    }
  },
}

function createHttpConnection(res, err) {
  if (!res) {
    return null
  }
  const headersMap = new Map()
  Object.keys(res.headers).forEach(key => {
    if (typeof res.headers[key] === 'string') {
      headersMap.set(key, res.headers[key])
    }
  })
  const NJSHttpUrlConnectionImpl = {
    getStatusCode: () => Number(res.status),
    getStatusText: () => res.statusText,
    getHeaders: () => headersMap,
    readBody: () => ({
      error: err ? { code: 0, message: 'something went wrong' } : null,
      data: stringToBytesArray(JSON.stringify(res.data)),
    }),
  }
  return new binding.NJSHttpUrlConnection(NJSHttpUrlConnectionImpl)
}

const NJSHttpClient = new binding.NJSHttpClient(NJSHttpClientImpl)

//                     ---------------------------------
//                     NJSWebSocketClient Implementation
//                     ---------------------------------

const NJSWebSocketClientImpl = {}

/**
 * @param: url: string
 * @param: connection: NJSWebSocketConnection
 */
NJSWebSocketClientImpl.connect = (url, connection) => {
  connection.OnConnect()
}

/**
 * @param: connection: NJSWebSocketConnection
 * @param: data: string
 */
NJSWebSocketClientImpl.send = (connection, data) => {
  connection.OnMessage(data)
}

/**
 * @param: connection: NJSWebSocketConnection
 */
NJSWebSocketClientImpl.disconnect = connection => {
  connection.OnClose()
}
const NJSWebSocketClient = new binding.NJSWebSocketClient(NJSWebSocketClientImpl)

//                         -------------------------
//                         LogPrinter implementation
//                         -------------------------

const NJSLogPrinterImpl = {
  context: {},
}

/**
 * @param: message: string
 */
const logger = (title, message) => {
  if (message) {
    // console.log(message);
  }
}

NJSLogPrinterImpl.printError = message => logger('Error', message)
NJSLogPrinterImpl.printInfo = message => logger('Info', message)
NJSLogPrinterImpl.printDebug = message => logger('Debug', message)
NJSLogPrinterImpl.printWarning = message => logger('Warning', message)
NJSLogPrinterImpl.printApdu = message => logger('Apdu', message)
NJSLogPrinterImpl.printCriticalError = message => logger('Critical Error', message)

/**
 * @return: main NJSExecutionContext
 */
NJSLogPrinterImpl.getContext = () => NJSThreadDispatcher.getMainExecutionContext()

const NJSLogPrinter = new binding.NJSLogPrinter(NJSLogPrinterImpl)

//                    ------------------------------------
//                    RandomNumberGenerator implementation
//                    ------------------------------------

const NJSRandomNumberGeneratorImpl = {}

NJSRandomNumberGeneratorImpl.getRandomBytes = size => crypto.randomBytes(size)
NJSRandomNumberGeneratorImpl.getRandomInt = () => Math.random() * MAX_RANDOM
NJSRandomNumberGeneratorImpl.getRandomLong = () => Math.random() * MAX_RANDOM * MAX_RANDOM
NJSRandomNumberGeneratorImpl.getRandomLong = () => crypto.randomBytes(1)

const NJSRandomNumberGenerator = new binding.NJSRandomNumberGenerator(NJSRandomNumberGeneratorImpl)

//                          -----------------------
//                          Instanciate C++ objects
//                          -----------------------

const NJSDatabaseBackend = new binding.NJSDatabaseBackend()
const NJSDynamicObject = new binding.NJSDynamicObject()
const NJSNetworks = new binding.NJSNetworks()

let NJSWalletPool = null

exports.instanciateWalletPool = ({ dbPath }) => {
  try {
    fs.mkdirSync(dbPath)
  } catch (err) {
    if (err.code !== 'EEXIST') {
      throw err
      process.exit(1)
    }
  }

  const NJSPathResolverImpl = {}

  /**
   * Resolves the path of a single log file
   *
   * @param: path: string
   * @return: resolved path
   */
  NJSPathResolverImpl.resolveLogFilePath = pathToResolve => {
    let hash = pathToResolve.replace(/\//g, '__')
    return path.resolve(dbPath, `./log_file_${hash}`)
  }

  /**
   * Resolves the path for a json file
   *
   * @param: path: string
   * @return: resolved path
   */
  NJSPathResolverImpl.resolvePreferencesPath = pathToResolve => {
    let hash = `${pathToResolve.replace(/\//g, '__')}_${process.pid}`
    return path.resolve(dbPath, `./preferences_${hash}`)
  }

  /**
   * Resolves the path for a SQLite database file.
   * @param: path: string
   * @return: resolved path
   */
  NJSPathResolverImpl.resolveDatabasePath = pathToResolve => {
    let hash = pathToResolve.replace(/\//g, '__')
    return path.resolve(dbPath, `./database_${hash}`)
  }

  const NJSPathResolver = new binding.NJSPathResolver(NJSPathResolverImpl)

  NJSWalletPool = new binding.NJSWalletPool(
    'ledger_live_desktop',
    '',
    NJSHttpClient,
    NJSWebSocketClient,
    NJSPathResolver,
    NJSLogPrinter,
    NJSThreadDispatcher,
    NJSRandomNumberGenerator,
    NJSDatabaseBackend,
    NJSDynamicObject,
  )

  return NJSWalletPool
}

//                                  -------
//                                  Exports
//                                  -------

exports.EVENT_CODE = EVENT_CODE
exports.SIGHASH_TYPES = SIGHASH_TYPES
exports.TIME_PERIODS = TIME_PERIODS
exports.OPERATION_TYPES = OPERATION_TYPES

exports.NJSLedgerCore = binding.NJSLedgerCore
exports.NJSAmount = binding.NJSAmount

// TODO in future we will deprecate usage of following functions
// and prefer using the NJSWalletPool object returned from instanciateWalletPool

exports.getWallet = function getWallet(walletName) {
  return NJSWalletPool.getWallet(walletName)
}

exports.createWallet = async (name, currency, njsConfig) => {
  const wallet = await NJSWalletPool.createWallet(name, currency, njsConfig)
  return wallet
}

exports.createAmount = (currency, amount) => {
  const a = new binding.NJSAmount(currency, amount)
  return a.fromLong(currency, amount)
}

exports.getCurrency = currencyName => NJSWalletPool.getCurrency(currencyName)

exports.getNextAccountCreationInfo = wallet => wallet.getNextAccountCreationInfo()

exports.createAccount = async (wallet, hwApp) => {
  const accountCreationInfos = await wallet.getNextAccountCreationInfo()
  await accountCreationInfos.derivations.reduce(
    (promise, derivation) =>
      promise.then(async () => {
        const { publicKey, chainCode, bitcoinAddress } = await hwApp.getWalletPublicKey(derivation)
        accountCreationInfos.publicKeys.push(hexToBytes(publicKey))
        accountCreationInfos.chainCodes.push(hexToBytes(chainCode))
      }),
    Promise.resolve(),
  )
  return wallet.newAccountWithInfo(accountCreationInfos)
}

exports.createWalletUid = function createWalletUid(walletName) {
  return crypto
    .createHash('sha256')
    .update(walletName)
    .digest('hex')
}

function createEventReceiver(cb) {
  return new binding.NJSEventReceiver({
    onEvent: event => cb(event),
  })
}
exports.createEventReceiver = createEventReceiver

function subscribeToEventBus(eventBus, receiver) {
  eventBus.subscribe(NJSThreadDispatcherImpl.contexts.main, receiver)
}
exports.subscribeToEventBus = subscribeToEventBus

exports.syncAccount = function syncAccount(account) {
  return new Promise((resolve, reject) => {
    const eventReceiver = createEventReceiver(e => {
      const code = e.getCode()
      if (code === EVENT_CODE.UNDEFINED || code === EVENT_CODE.SYNCHRONIZATION_FAILED) {
        return reject(new Error('Sync failed'))
      }
      if (
        code === EVENT_CODE.SYNCHRONIZATION_SUCCEED ||
        code === EVENT_CODE.SYNCHRONIZATION_SUCCEED_ON_PREVIOUSLY_EMPTY_ACCOUNT
      ) {
        resolve(() => {
          eventBus.unsubscribe(eventReceiver)
        })
      }
    })
    const eventBus = account.synchronize()
    subscribeToEventBus(eventBus, eventReceiver)
  })
}

exports.createWalletConfig = (configMap = {}) => {
  const config = new binding.NJSDynamicObject()
  for (let i in configMap) {
    if (configMap.hasOwnProperty(i)) {
      config.putString(i, configMap[i])
    }
  }
  return config
}

exports.signTransaction = signTransaction
