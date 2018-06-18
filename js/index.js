module.exports = Object.assign({}, require('bindings')('ledger-core-node'), {
  METHODS: {
    '0': 'GET',
    '1': 'POST',
    '2': 'PUT',
    '3': 'DELETE',
  },
  EVENT_CODE: {
    UNDEFINED: 0,
    NEW_OPERATION: 1,
    NEW_BLOCK: 2,
    SYNCHRONIZATION_STARTED: 3,
    SYNCHRONIZATION_FAILED: 4,
    SYNCHRONIZATION_SUCCEED: 5,
    SYNCHRONIZATION_SUCCEED_ON_PREVIOUSLY_EMPTY_ACCOUNT: 6,
  },

  SIGHASH_TYPES: {
    SIGHASH_ALL: 1,
    SIGHASH_NONE: 2,
    SIGHASH_SINGLE: 3,
    SIGHASH_FORKID: 0x40,
    SIGHASH_ANYONECANPAY: 0x80,
  },

  TIME_PERIODS: {
    DAY: 0,
    WEEK: 1,
    MONTH: 2,
  },
  OPERATION_TYPES: {
    SEND: 0,
    RECEIVE: 1,
  },
})
