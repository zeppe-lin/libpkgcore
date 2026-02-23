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
# Feature toggles
# ===================================================================
# Usage: make ACL=y XATTR=y
# Requires libarchive built with corresponding support.

# Enable restoring Access Control Lists (ACLs)
OPT_ACL_y   = -DENABLE_EXTRACT_ACL

# Enable restoring extended attributes (xattr)
OPT_XATTR_y = -DENABLE_EXTRACT_XATTR

# ===================================================================
# Compiler and archiver flags
# ===================================================================
CPPFLAGS    = -D_POSIX_SOURCE -D_GNU_SOURCE -D_LARGEFILE_SOURCE \
              -D_FILE_OFFSET_BITS=64 -DNDEBUG \
              -DNAME=\"$(NAME)\" -DVERSION=\"$(VERSION)\" \
              $(OPT_ACL_$(ACL)) $(OPT_XATTR_$(XATTR))
CXXFLAGS    = -std=c++0x -pedantic -Wall -Wextra
ARFLAGS     = rcs

# ===================================================================
# Toolchain
# ===================================================================
CXX         = c++
AR          = ar
