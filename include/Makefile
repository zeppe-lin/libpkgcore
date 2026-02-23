.POSIX:

include ../config.mk

HEADER1 = libpkgcore.h
HEADER2 = pkgcore/db_lock.h pkgcore/fs_utils.h pkgcore/pkgutil.h

ALL_HEADERS = $(HEADER1) $(HEADER2)

all:

install: all
	mkdir -p $(DESTDIR)$(PREFIX)/include/pkgcore
	cp -f $(HEADER1) $(DESTDIR)$(PREFIX)/include
	cp -f $(HEADER2) $(DESTDIR)$(PREFIX)/include/pkgcore
	cd $(DESTDIR)$(PREFIX)/include && chmod 0644 $(ALL_HEADERS)

uninstall:
	cd $(DESTDIR)$(PREFIX)/include && rm -f $(ALL_HEADERS)

clean:

.PHONY: all install uninstall clean
