# BUILD 03-09-2023

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
CC = gcc
CFLAGS = -std=c99
#CXXFLAGS = -Wall -std=c++11 -DDEBUG -g
#CXXFLAGS = -Wall -std=c++11 -std=gnu++17
CXXFLAGS = -Wall -std=c++20
#CXXFLAGS = -Wall -std=gnu++2b
#CXXFLAGS += -DDEBUG -g
CXXFLAGS += -DDEBUG -ggdb

# lib settings
# cppunit IS NOT USED!
# LDFLAGS = -static -lcppunit -L/usr/local/lib/
# INCLUDES = -I/usr/local/include/cppunit/
# add addtional libs here
#LDFLAGS = -static -llibfmt -L/usr/local/lib64/
#INCLUDES = -I/usr/local/include/fmt/

# Makefile settings - Can be customized.
APPNAME = examples
EXT = cpp
ROOTDIR  = .
USR_SRCDIR = ../$(ROOTDIR)
BUILDDIR = ./build
SRCDIR = $(ROOTDIR)/src
OBJDIR = ./build

# compile & link for debug
#debug: CXXFLAGS += -DDEBUG -g
debug: all

# compile & link for debug GDBversion variable
#debuggdb: CXXFLAGS += -DDEBUG -ggdb # compile & link

all:: std_array 
all:: faq1.1 faq1.2 
all:: read_lines iter_files
all:: boost_test boost_regex boost_exedir 
all:: regex_replace_example
all:: sample_formats
all:: sample_userType
all:: regx_replace1 sub_match sub_match sub_match2
all:: dump_ifstream map_insert
all:: template_ex1 
all:: fmtlib.ex1 fmtlib.play 
all:: string_view_test math_consts
all:: cfilesys atoi_itoa
all:: istream threads_ex1
#all:: gtk_hello gtk_example-0

test:
	ls $? $(SRCDIR)

std_array:
	$(CXX) $(CXXFLAGS) $(SRCDIR)/std_array.cpp -o $(BUILDDIR)/std_array

faq1.1:
	$(CXX) $(CXXFLAGS) $(SRCDIR)/faq1.1.cpp -o $(BUILDDIR)/faq1.1

faq1.2:
	$(CXX) $(CXXFLAGS) $(SRCDIR)/faq1.2.cpp -o $(BUILDDIR)/faq1.2

read_lines:
	$(CXX) $(CXXFLAGS) $(SRCDIR)/read_lines.cpp -o $(BUILDDIR)/read_lines

iter_files:
	$(CXX) $(CXXFLAGS) $(SRCDIR)/iter_files.cpp -o $(BUILDDIR)/iter_files

boost_test:
	$(CXX) $(CXXFLAGS) -I $(USR_SRCDIR)/boost_1_79_0 $(SRCDIR)/boost_test.cpp -o $(BUILDDIR)/boost_test

boost_regex:
	#$(CXX) $(CXXFLAGS) -I $(USR_SRCDIR)/src/boost_1_79_0 $(SRCDIR)/boost_regex.cpp -o $(BUILDDIR)/boost_regex

boost_exedir:
	$(CXX) $(CXXFLAGS) -I $(USR_SRCDIR)/boost_1_79_0 $(SRCDIR)/boost_exedir.cpp -o $(BUILDDIR)/boost_exedir

# boost_mpi:
# 	$(CXX) $(CXXFLAGS) -I ~/src/boost_1_79_0/boost -lboost_mpi -lboost_serialization $(SRCDIR)/boost_mpi.cpp -o $(BUILDDIR)/boost_mpi

regx_replace1:
	$(CXX) $(CXXFLAGS) $(SRCDIR)/regx_replace1.cpp -o $(BUILDDIR)/regx_replace1

regex_replace_example: regex_replace_example.o
	$(CXX) $(CXXFLAGS) -I $(USR_SRCDIR)/boost_1_79_0 $(BUILDDIR)/regex_replace_example.o -o $(BUILDDIR)/regex_replace_example

regex_replace_example.o:
	$(CXX) $(CXXFLAGS) -I $(USR_SRCDIR)/boost_1_79_0 -c $(SRCDIR)/regex_replace_example.cpp -o $(BUILDDIR)/regex_replace_example.o

sample_formats:
	$(CXX) $(CXXFLAGS) -I $(USR_SRCDIR)/boost_1_79_0 $(SRCDIR)/sample_formats.cpp -o $(BUILDDIR)/sample_formats

sample_userType:
	$(CXX) $(CXXFLAGS) -I $(USR_SRCDIR)/boost_1_79_0 $(SRCDIR)/sample_userType.cpp -o $(BUILDDIR)/sample_userType
	
sub_match:
	$(CXX) $(CXXFLAGS) $(SRCDIR)/sub_match.cpp -o $(BUILDDIR)/sub_match

sub_match2:
	$(CXX) $(CXXFLAGS) $(SRCDIR)/sub_match2.cpp -o $(BUILDDIR)/sub_match2

dump_ifstream:
	$(CXX) $(CXXFLAGS) $(SRCDIR)/dump_ifstream.cpp $(SRCDIR)/utility.cpp -o $(BUILDDIR)/dump_ifstream

map_insert:
	$(CXX) $(CXXFLAGS) $(SRCDIR)/map_insert.cpp -o $(BUILDDIR)/map_insert

template_ex1:
	$(CXX) $(CXXFLAGS) $(SRCDIR)/template_ex1.cpp -o $(BUILDDIR)/template_ex1

gtk_hello:
	@echo "MAKE RULE - gtk_hello: disabled"
	#gcc $(SRCDIR)/gtk_hello.c -o $(BUILDDIR)/gtk_hello `pkg-config --cflags --libs gtk+-3.0`

gtk_example-0:
	@echo "MAKE RULE - gtk_example-0: disabled"
	#gcc `pkg-config --cflags gtk+-3.0` -o $(BUILDDIR)/gtk_example-0 $(SRCDIR)/gtk_example-0.c `pkg-config --libs gtk+-3.0`

stl_format:
	$(CXX) $(CXXFLAGS) $(SRCDIR)/stl_format.cpp -o $(BUILDDIR)/stl_format

fmtlib.ex1:
	$(CXX) $(CXXFLAGS) $(SRCDIR)/fmtlib.ex1.cpp /usr/local/lib64/libfmt.a -o $(BUILDDIR)/fmtlib.ex1

fmtlib.play:
	$(CXX) $(CXXFLAGS) $(SRCDIR)/fmtlib.play.cpp /usr/local/lib64/libfmt.a -o $(BUILDDIR)/fmtlib.play

string_view_test:
	$(CXX) $(CXXFLAGS) $(SRCDIR)/string_view_test.cpp -o $(BUILDDIR)/string_view_test

math_consts:
	$(CXX) $(CXXFLAGS) $(SRCDIR)/math_consts.cpp -o $(BUILDDIR)/math_consts

cfilesys:
	$(CC) $(CFLAGS) $(SRCDIR)/cfilesys.c -o $(BUILDDIR)/cfilesys

atoi_itoa:
	$(CC) $(CFLAGS) $(SRCDIR)/atoi_itoa.c -o $(BUILDDIR)/atoi_itoa

istream:
	$(CXX) $(CXXFLAGS) $(SRCDIR)/istream.cpp -o $(BUILDDIR)/istream

threads_ex1:
	$(CXX) $(CXXFLAGS) $(SRCDIR)/threads_ex1.cpp -o $(BUILDDIR)/threads_ex1

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
	-rm $(BUILDDIR)/*
	# -rm -f $(BUILDDIR)/$(APPNAME) $(BUILDDIR)/*.o $(BUILDDIR)/$(APPNAME)_test $(BUILDDIR)/bash_color_test
	# -rm -f $(BUILDDIR)/*.xml $(BUILDDIR)/$(APPNAME).$(BUILD_VERSION).tar.gz
	# -rm -f $(BUILDDIR)/std_array
	# -rm -f $(BUILDDIR)/read_lines $(BUILDDIR)/iter_files $(BUILDDIR)/boost_test $(BUILDDIR)/boost_regex $(BUILDDIR)/regx_replace1
	# -rm -f $(BUILDDIR)/sub_match $(BUILDDIR)/sub_match2 $(BUILDDIR)/boost_exedir  $(BUILDDIR)/dump_ifstream $(BUILDDIR)/map_insert
	# -rm -f $(BUILDDIR)/gtk_hello 
	# -rm -f $(BUILDDIR)/gtk_example-0
	# -rm -f $(BUILDDIR)/template_ex1
	# -rm -f $(BUILDDIR)/string_view_test
	# -rm -f $(BUILDDIR)/math_consts
	# -rm -f $(BUILDDIR)/faq1.1
	# -rm -f $(BUILDDIR)/faq1.2
	# -rm -f $(BUILDDIR)/fmtlib.ex1
	# -rm -f $(BUILDDIR)/fmtlib.playn

# delete all auto generated files
.PHONY: distclean
distclean: clean
	-rm -f $(SRCDIR)/config.* $(SRCDIR)/Makefile $(SRCDIR)/Makefile.in $(SRCDIR)/INSTALL $(SRCDIR)/configure 
	# rm ../stamp-h1 ../aclocal.m4 ../compile ../install-sh ../libtool ../ltmain.sh ../stamp-h1 ../missing ../depcomp
	# rm ../src/Makefile ../src/Makefile.in
	# rm -rf ../autom4te.cache ../src/.deps ../src/.libs
	# rm ../src/.o

dist: 
	git archive HEAD | gzip > $(BUILDDIR)/$(APPNAME).$(BUILD_VERSION).tar.gz
