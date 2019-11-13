{
  'variables': {
    'target_module_name': 'ledger-core-node',
    'conditions': [
      ['OS=="mac"', { 'wrapper_libs': '<(module_root_dir)/lib/libledger-core.dylib'}],
      ['OS=="win"', { 'wrapper_libs': '<(module_root_dir)/lib/ledger-core.lib' }],
      ['OS=="linux"', { 'wrapper_libs': '<(module_root_dir)/lib/libledger-core.so' }],
    ]
  },
  "includes": ["ubinder/src/node/ubinder.gypi"],
  "targets":
  [
    {
        "target_name": "copy_binary",
        "type":"none",
        'conditions': [
            ['OS=="win"', {
                "copies":
                [
                    {
                        'destination': '<(module_root_dir)/build/Release/',
                        'files': [ '<(module_root_dir)/lib/ledger-core.lib' ]
                    }
                ]
            }],
            ['OS!="win"', {
                "copies":
                [
                    {
                        'destination': '<(module_root_dir)/build/Release/',
                        'files': [ '<(module_root_dir)/lib/libledger-core<(SHARED_LIB_SUFFIX)' ]
                    }
                ]
            }],
        ]
    }
  ]
}
