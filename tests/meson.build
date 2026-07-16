if get_option('tests').allowed()
  pkgutil_signal_neutral_test = executable(
    'pkgutil-signal-neutral-test',
    'pkgutil_signal_neutral.cpp',
    dependencies: libpkgcore_dep,
  )

  test('pkgutil preserves signal state', pkgutil_signal_neutral_test)
endif
