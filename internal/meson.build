conf = configuration_data()
conf.set_quoted('PACKAGE_NAME', meson.project_name())
conf.set_quoted('PACKAGE_VERSION', meson.project_version())
conf.set10('ENABLE_EXTRACT_ACL', get_option('extract_acl'))
conf.set10('ENABLE_EXTRACT_XATTR', get_option('extract_xattr'))

configure_file(
  output: 'libpkgcore-config.h',
  configuration: conf,
)

internal_inc = include_directories('.')
