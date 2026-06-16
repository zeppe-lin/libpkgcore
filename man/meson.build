if get_option('manpages')
  scdoc = find_program('scdoc')

  foreach section, pages: {
    '3': [ 'db_lock', 'fs_utils', 'pkgutil' ],
    '7': [ 'libpkgcore' ],
  }
    foreach page: pages
      custom_target(
        page + '.' + section,
        input: page + '.' + section + '.scdoc',
        output: page + '.' + section,
        command: [scdoc],
        feed: true,
        capture: true,
        install: true,
        install_dir: get_option('mandir') / ('man' + section),
        install_tag: 'man',
      )
    endforeach
  endforeach
endif
