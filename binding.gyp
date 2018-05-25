{
  'variables': {
    'core_library%': 'lib',
    'source_path%': 'src',
  },
  'targets': [
    {
      'target_name': 'ledger-core',
      'sources': ["<!@(python glob.py <@(source_path) *.cpp *.hpp)"],
      'include_dirs': [
        "<!(node -e \"require('nan')\")",
        "<!(pwd)/include",
      ],
      'all_dependent_settings': {
        'include_dirs': ["<!(node -e \"require('nan')\")"],
      },
      'libraries': [
        '-L<!(pwd)/<@(core_library)',
        '-lledger-core'
      ],
      "copies": [
        {
          'destination': '<(module_root_dir)/build/Release/',
          'files': ['<(module_root_dir)/<@(core_library)/libledger-core<(SHARED_LIB_SUFFIX)']
        }
      ],
      'conditions': [
        ['OS=="mac"', {
          'LDFLAGS': [
            '-framework IOKit',
            '-framework CoreFoundation',
            '-DYLD_LIBRARY_PATH '
          ],
          'xcode_settings': {
            'GCC_ENABLE_CPP_EXCEPTIONS': 'YES',
            'OTHER_CFLAGS': [
              '-ObjC++',
              '-std=c++14',
            ],
            'OTHER_LDFLAGS': [
              '-framework IOKit',
              '-framework CoreFoundation',
              '-Xlinker -rpath -Xlinker @loader_path'
            ],
          },
        }
      ],
      [
        'OS=="win"', {
          'GCC_ENABLE_CPP_EXCEPTIONS': 'YES',
          'OTHER_CFLAGS': ['-std=c++14']
        }
      ],
      ['OS=="linux"', {
          'ldflags': [
            '-Wl,-R,\'$$ORIGIN\''
          ]
        }
      ]
    ],
    'cflags!': ['-ansi', '-fno-exceptions'],
    'cflags_cc!': ['-fno-exceptions'],
    'cflags': ['-g', '-exceptions'],
    'cflags_cc': ['-g', '-exceptions']
  }]
}
