project(
  'libpkgcore',
  'cpp',
  version : '6.3',
  default_options : [
    'cpp_std=c++11',
    'warning_level=3',
    'default_library=both',
    'b_ndebug=if-release',
  ],
)

libarchive_dep = dependency('libarchive', required : true)
pkgconf = import('pkgconfig')

subdir('internal')
subdir('src')
#subdir('man')
#subdir('tests')
