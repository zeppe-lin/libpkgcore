.POSIX:
.SUFFIXES: .cpp .o

include ../config.mk
#include ../extra/flags-extra.mk
#include ../extra/flags-sanitizer.mk

LIB  = libpkgcore.a
OBJS = db_lock.o fs_utils.o pkgutil.o

all: $(LIB)

.cpp.o:
	$(CXX) -c $< -I../include $(CPPFLAGS) $(CXXFLAGS)

$(LIB): $(OBJS)
	$(AR) $(ARFLAGS) $@ $^

install: all
	mkdir -p $(DESTDIR)$(PREFIX)/lib
	cp -f $(LIB) $(DESTDIR)$(PREFIX)/lib

uninstall:
	cd $(DESTDIR)$(PREFIX)/lib  && rm -f $(LIB)

clean:
	rm -f $(OBJS) $(LIB)

.PHONY: all install uninstall clean
