const { bytesToHex, stringToBytesArray, hexToBytes } = require('./helpers')

async function signTransaction({
  hwApp,
  transaction,
  sigHashType = SIGASH_TYPES.SIGHASH_ALL,
  supportsSegwit = true,
  isSegwit = true,
  hasTimestamp = false,
}) {
  const rawInputs = transaction.getInputs()

  const inputs = await Promise.all(
    rawInputs.map(async input => {
      const rawPreviousTransaction = await input.getPreviousTransaction()
      const hexPreviousTransaction = bytesToHex(rawPreviousTransaction)
      const previousTransaction = hwApp.splitTransaction(hexPreviousTransaction, supportsSegwit, hasTimestamp)
      const outputIndex = input.getPreviousOutputIndex()
      const sequence = input.getSequence()
      return [
        previousTransaction,
        outputIndex,
        undefined, // we don't use that TODO: document
        sequence, // 0xffffffff,
      ]
    }),
  )

  const associatedKeysets = rawInputs.map(input => {
    const derivationPaths = input.getDerivationPath()
    return derivationPaths[0].toString()
  })

  const outputs = transaction.getOutputs()

  const output = outputs.find((output, i) => {
    const derivationPath = output.getDerivationPath()
    if (derivationPath.isNull()) {
      return false
    }
    const strDerivationPath = derivationPath.toString()
    const derivationArr = strDerivationPath.split('/')
    return derivationArr[derivationArr.length - 2] === '1'
  })

  const changePath = output ? output.getDerivationPath().toString() : undefined
  const outputScriptHex = bytesToHex(transaction.serializeOutputs())
  const lockTime = transaction.getLockTime()
  const initialTimestamp = hasTimestamp ? transaction.getTimestamp() : undefined

  const signedTransaction = await hwApp.createPaymentTransactionNew(
    inputs,
    associatedKeysets,
    changePath,
    outputScriptHex,
    lockTime,
    sigHashType,
    isSegwit,
    initialTimestamp,
  )

  console.log(signedTransaction)

  return hexToBytes(signedTransaction)
}

module.exports = signTransaction
