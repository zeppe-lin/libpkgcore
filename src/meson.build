public_inc = include_directories('../include')

libpkgcore = library(
  'pkgcore',
  [
    'db_lock.cpp',
    'fs_utils.cpp',
    'pkgutil.cpp',
  ],
  cpp_args: ['-D_FILE_OFFSET_BITS=64'],
  include_directories: [public_inc, internal_inc],
  dependencies: [libarchive_dep],
  install: true,
  version: meson.project_version(),
  soversion: '6',
)

libpkgcore_dep = declare_dependency(
  link_with: libpkgcore,
  include_directories: public_inc,
  dependencies: [libarchive_dep],
  compile_args: ['-D_FILE_OFFSET_BITS=64'],
)

meson.override_dependency('libpkgcore', libpkgcore_dep)

install_headers(
  '../include/libpkgcore/pkgcore.h',
  '../include/libpkgcore/db_lock.h',
  '../include/libpkgcore/fs_utils.h',
  '../include/libpkgcore/pkgutil.h',
  subdir: 'libpkgcore',
)

pkgconf.generate(
  libpkgcore,
  name: 'libpkgcore',
  filebase: 'libpkgcore',
  description: 'Core package management library',
  subdirs: 'libpkgcore',
  requires_private: ['libarchive'],
)
