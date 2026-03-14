OVERVIEW
========

`libpkgcore` is the core package management library extracted from
CRUX `pkgutils`.
It provides foundational classes and functions for package utilities
such as `pkgadd(8)`, `pkgrm(8)`, and `pkginfo(1)` - handling package
installation, removal, and information queries.

This distribution is a fork of CRUX `pkgutils` at commit 9ca0da6
(Sat Nov 17 2018) with the following differences:
  * Code organized into a standalone library (`libpkgcore`) and
    utilities ([pkgutils](https://github.com/zeppe-lin/pkgutils))
  * Support for `zstd` archive formats
  * Optional support for preserving ACLs and xattrs

See the git log for full history.

Original sources:
  * https://git.crux.nu/tools/pkgutils.git

---

REQUIREMENTS
============

Build-time
----------
  * C++11 compiler (GCC 4.8.1+, Clang 3.3+)
  * Meson
  * Ninja
  * `pkg-config(1)`
  * `libarchive(3)` headers and library

---

INSTALLATION
============

General
-------

```sh
# Configure
meson setup build

# Compile
meson compile -C build

# Install
meson install -C build
```

Options
-------

Enable ACL support:

```sh
meson setup build -Dextract_acl=true
```

Enable xattr support:

```sh
meson setup build -Dextract_xattr=true
```

Enable both:

```sh
meson setup build -Dextract_acl=true -Dextract_xattr=true
```

Library type
------------

Shared:

```sh
meson setup build -Ddefault_library=shared
```

Static:

```sh
meson setup build -Ddefault_library=static
```

Both:

```sh
meson setup build -Ddefault_library=both
```

For generic static-library packaging, disabling LTO is recommended:

```sh
meson setup build -Ddefault_library=static -Db_lto=false
```

Build type
----------

Debug:

```sh
meson setup build -Dbuildtype=debug
```

Release:

```sh
meson setup build -Dbuildtype=release -Db_ndebug=if-release
```

pkg-config
----------

Compiler flags:

```sh
pkg-config --cflags libpkgcore
```

Link flags:

```sh
pkg-config --libs libpkgcore
```

Static link flags:

```sh
pkg-config --static --libs libpkgcore
```

Layout
------

- `include/` - public headers
- `src/` - library sources
- `internal/` - internal headers

---

DOCUMENTATION
=============

Library API is documented in header files under `include/libpkgcore`.

---

LICENSE
=======

`libpkgcore` is licensed under the
[GNU General Public License v2 or later](https://gnu.org/licenses/gpl.html).

See `COPYING` for license terms and `COPYRIGHT` for notices.
