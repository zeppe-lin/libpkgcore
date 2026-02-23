OVERVIEW
========

`libpkgcore` is the core package management library extracted from
CRUX `pkgutils`.
It provides foundational classes and functions for package utilities
such as `pkgadd(8)`, `pkgrm(8)`, and `pkginfo(1)` - handling package
installation, removal, and information queries.

This distribution is a fork of CRUX `pkgutils` at commit 9ca0da6
(Sat Nov 17 2018) with the following differences:
  * Code organized into a standalone library (`libpkgutils`)
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
  * POSIX `sh(1p)`, `make(1p)`, and "mandatory utilities"
  * `libarchive(3)` headers and library

---

INSTALLATION
============

To build and install:

```sh
make
make install   # as root
```

Configuration parameters are defined in `config.mk`.

---

DOCUMENTATION
=============

Library API is documented in header files under `include/pkgcore`.

---

LICENSE
=======

`libpkgcore` is licensed under the
[GNU General Public License v2 or later](https://gnu.org/licenses/gpl.html).

See `COPYING` for license terms and `COPYRIGHT` for notices.
