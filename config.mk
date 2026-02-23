# ===================================================================
# Project metadata
# ===================================================================
NAME        = libpkgcore
VERSION     = 6.3

# ===================================================================
# Installation paths
# ===================================================================
PREFIX      = /usr/local
MANPREFIX   = $(PREFIX)/share/man
PKGCONFDIR  = $(PREFIX)/lib/pkgconfig

# ===================================================================
# Feature toggles (libarchive extraction options)
# ===================================================================
# Uncomment to enable restoring Access Control Lists (ACLs).
# Requires libarchive built with ACL support.
#ACL        = -DENABLE_EXTRACT_ACL
#
# Uncomment to enable restoring extended attributes (xattrs)
# Requires libarchive built with xattr support.
#XATTR      = -DENABLE_EXTRACT_XATTR

# ===================================================================
# Compiler and archiver flags
# ===================================================================
CPPFLAGS    = -D_POSIX_SOURCE -D_GNU_SOURCE -D_LARGEFILE_SOURCE \
              -D_FILE_OFFSET_BITS=64 -DNDEBUG \
              -DNAME=\"$(NAME)\" -DVERSION=\"$(VERSION)\" \
              $(ACL) $(XATTR)
CXXFLAGS    = -std=c++0x -pedantic -Wall -Wextra
ARFLAGS     = rcs

# ===================================================================
# Toolchain
# ===================================================================
CXX         = c++
AR          = ar
