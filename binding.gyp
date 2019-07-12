{
  'variables': {
    'target_module_name': 'ledger-core-node',
    'conditions': [
      ['OS=="win"', { 'wrapper_libs': '<(module_root_dir)/lib/ledger-core.lib' }],
      ['OS=="linux"', { 'wrapper_libs': '<(module_root_dir)/lib/libledger-core.so' }],
    ]
  },
  "includes": ["node_modules/ubinder/src/node/ubinder.gypi"]
}
