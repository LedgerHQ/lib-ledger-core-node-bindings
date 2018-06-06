exports.bytesArrayToString = (bytesArray = []) => Buffer.from(bytesArray).toString()

exports.stringToBytesArray = str => Array.from(Buffer.from(str))

exports.hexToBytes = str => Array.from(Buffer.from(str, 'hex'))

exports.bytesToHex = (bytes = []) => Buffer.from(bytes).toString('hex')

function createBitcoinLikeHelper() {
  const binding = require('bindings')('ledger-core')
  return new binding.NJSBitcoinLikeHelper()
}
exports.createBitcoinLikeHelper = createBitcoinLikeHelper
