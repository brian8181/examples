# MAKE TEMPLATE 06-02-2020 1
# MAKE TEMPLATE 03-11-2021 1.1
# MAKE TEMPLATE 05-22-2021 1.2
# MAKE TEMPLATE 07-07-2021 1.3

# RUN BEFORE autoreconf -ivfm
# RUN BEFORE autoreconf -i

MAKE_TEMPLATE = 1.3;
BUILD_VERSION = 0.1.0

prefix = /usr/local
prefix = /usr/local
mandir = $(prefix)/share/man
man1dir = $(mandir)/man1

# Compiler settings - Can be customized.
CXX = g++
#CXXFLAGS = -Wall -std=c++11 -DDEBUG -g

# HACK!
CXXFLAGS = -Wall -std=c++11 -std=gnu++17
#CXXFLAGS += -DDEBUG -g
CXXFLAGS += -DDEBUG -ggdb


# lib settings
LDFLAGS = -ltag -L/usr/local/lib/ -lz
INCLUDES= -I/usr/local/include/taglib/
# add addtional libs here

# Makefile settings - Can be customized.
APPNAME = tag_art
EXT = cpp
ROOTDIR  = .
BUILDDIR = ./build
SRCDIR = ./src
OBJDIR = ./build

# compile & link for debug
#debug: CXXFLAGS += -DDEBUG -g
debug: all

# compile & link for debug GDBversion variable
#debuggdb: CXXFLAGS += -DDEBUG -ggdb # compile & link
all: $(APPNAME)

# link
$(APPNAME): $(APPNAME).o #END
	 $(CXX) $(CXXFLAGS) $(BUILDDIR)/$(APPNAME).o $(INCLUDES) $(LDFLAGS) -o $(BUILDDIR)/$(APPNAME)

# compile only
$(APPNAME).o:
	$(CXX) $(CXXFLAGS) -c $(SRCDIR)/$(APPNAME).$(EXT) $(INCLUDES) $(LDFLAGS) -o $(BUILDDIR)/$(APPNAME).o
	
main.o:
	$(CXX) $(CXXFLAGS) -c $(SRCDIR)/main.$(EXT) -o $(BUILDDIR)/main.o
	
## auto gernerated here ##

# link
$(APPNAME)_test: $(APPNAME)_test.o
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(BUILDDIR)/$(APPNAME)_test.o $(BUILDDIR)/$(APPNAME).o $(LDFLAGS) -o $(BUILDDIR)/$(APPNAME)_test

# compile only
$(APPNAME)_test.o:
	$(CXX) $(CXXFLAGS) -c $(SRCDIR)/$(APPNAME)_test.cpp -o $(BUILDDIR)/$(APPNAME)_test.o

bash_color_test: bash_color_test.o
	$(CXX) $(CXXFLAGS) $(BUILDDIR)/bash_color_test.o -o $(BUILDDIR)/bash_color_test

bash_color_test.o:
	$(CXX) $(CXXFLAGS) -c $(SRCDIR)/bash_color_test.cpp -o $(BUILDDIR)/bash_color_test.o

# install man pages
.PHONY: man
man:
	cp ../man/$(APPNAME).1 $(man1dir)
	# gzip $(man1dir)/$(APPNAME).1
	mandb

.PHONY: unman
unman:
	rm $(man1dir)/$(APPNAME).1.gz
	mandb

# install 
.PHONY: install
install: man
	cp $(BUILDDIR)/$(APPNAME) $(prefix)/bin/$(APPNAME)
	rm $(prefix)/bin/$(APPNAME)

# delete object files & app executable
.PHONY: clean
clean:
	-rm -f $(BUILDDIR)/$(APPNAME) 
	-rm -f $(BUILDDIR)/*.o 
	-rm -f $(BUILDDIR)/$(APPNAME)_test $(BUILDDIR)/bash_color_test
	-rm -f $(BUILDDIR)/*.xml $(BUILDDIR)/$(APPNAME).$(BUILD_VERSION).tar.gz


# delete all auto generated files
.PHONY: distclean
distclean: clean
	-rm -f $(SRCDIR)/config.* $(SRCDIR)/Makefile $(SRCDIR)/Makefile.in $(SRCDIR)/INSTALL $(SRCDIR)/configure 
	-rm -f ../stamp-h1 ../aclocal.m4 ../compile ../install-sh ../libtool ../ltmain.sh ../stamp-h1 ../missing ../depcomp
	-rm -f ../src/Makefile ../src/Makefile.in
	-rm -rf ../autom4te.cache ../src/.deps ../src/.libs
	-rm -f ../src/.o

dist: 
	git archive HEAD | gzip > $(BUILDDIR)/$(APPNAME).$(BUILD_VERSION).tar.gz
