project(
  'libpkgcore',
  'cpp',
  version: '6.5',
  default_options: [
    'cpp_std=c++11',
    'warning_level=3',
    'default_library=shared',
    'b_ndebug=if-release',
  ],
)

want_static = get_option('link_mode') == 'static'
if want_static and get_option('default_library') == 'both'
  error('''
Invalid configuration: link_mode=static requires default_library=static.
See project README: Link Mode.
''')
endif

libarchive_dep = dependency(
  'libarchive',
  required: true,
  static: want_static,
)

pkgconf = import('pkgconfig')

subdir('internal')
subdir('src')
subdir('man')
#subdir('tests')
