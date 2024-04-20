# File Name:  streamy.hpp
# Build Date: Fri Feb  2 04:35:18 AM CST 2024
# Version:    0.0.1

prefix=/usr/local
mandir=$(prefix)/share/man
man1dir=$(mandir)/man1

# Compiler settings - Can be customized.
CXX=g++
CC=gcc
CFLAGS = -std=c99
CXXFLAGS = -Wall -std=c++20
CXXFLAGS += -DDEBUG -ggdb
#CXXFLAGS = -Wall -std=c++11 -std=gnu++17

# lib settings
# cppunit IS NOT USED!(USR_SRC)/
# INCLUDES = -I/usr/local/include/cppunit/
# add addtional libs here
#LDFLAGS = -static -llibfmt -L/usr/local/lib64/fmt
#INCLUDES = -I/usr/local/include/fmt/

# Makefile settings - Can be customized.
APP=examples
EXT=cpp
ROOT=.
# install correctly or do this /usr/local/lib?
#USR_SRC = ../$(ROOT)
BLD=./build
SRC=$(ROOT)/src
OBJ=./build

# compile & link for debug
#debug: CXXFLAGS += -DDEBUG -g
# compile & link for debug GDBversion variable
#debuggdb: CXXFLAGS += -DDEBUG -ggdb # compile & link

all:: $(BLD)/std_array
# all:: std_array_ex
all:: faq1.1 faq1.2
#all:: read_lines iter_files
all:: boost_io bfs-example
all:: $(BLD)/boost_parse_xml
all:: boost_circular_buffer
all:: boost_regex_match
#all:: bfs-example2
all:: regx_replace1 sub_match sub_match sub_match2
all:: dump_ifstream map_insert
all:: template_ex1
all:: fmtlib.ex1 fmtlib.play
all:: string_view_test math_consts
all:: cfilesys atoi_itoa
all:: istream threads_ex1
#all:: gtk_hello gtk_example-0
all:: valarray_ex
all:: pipe_timeout
all:: signal_ex3
all:: vla_basic
all:: vla_sizeof
# link error!
#all:: vla_pass_vla
all:: vla_pass_mutivla
all:: vla_typedef
# link error!
#all:: itoa_example
all:: signals_ex1
all:: signals_ex4
all:: std_hex
all:: std_find_string
all:: std_find
all:: dice_unifrom_distribution
all:: get_current_dir
all:: stringstream_ex1
all:: constexpr_ex
all:: char2string
all:: filesystem_current_directory
all:: stl_set_difference
all:: strtok
all:: regex_search
all:: unique_ptr_example
#all:: regex_example
#all:: udpserver_example
# all:: mybuf
##all:: fmtlib.color.ex1.cpp
all:: $(BLD)/lambda01

# test:
# 	ls $? $(SRC)

$(BLD)/std_array: $(SRC)/std_array.cpp
	$(CXX) $(CXXFLAGS) $(SRC)/std_array.cpp -o $(BLD)/std_array

valarray_ex:
	$(CXX) $(CXXFLAGS) $(SRC)/valarray_ex.cpp -o $(BLD)/valarray_ex

faq1.1:
	$(CXX) $(CXXFLAGS) $(SRC)/faq1.1.cpp -o $(BLD)/faq1.1

faq1.2:
	$(CXX) $(CXXFLAGS) $(SRC)/faq1.2.cpp -o $(BLD)/faq1.2

read_lines:
	$(CXX) $(CXXFLAGS) $(SRC)/read_lines.cpp -o $(BLD)/read_lines

#$(CXX) $(CXXFLAGS) -I ~/src/boost_1_79_0/boost -lboost_mpi -lboost_serialization $(SRC)/boost_mpi.cpp -o $(BLD)/boost_mpi

$(BLD)/boost_parse_xml:
	$(CXX) $(CXXFLAGS) -I ~/src/boost_1_79_0 $(SRC)/boost_parse_xml.cpp -o $(BLD)/boost_parse_xml

boost_io:
	$(CXX) $(CXXFLAGS) -I ~/src/boost_1_79_0 $(SRC)/boost_io.cpp -o $(BLD)/boost_io

bfs-example:
	$(CXX) $(CXXFLAGS) -I ~/src/boost_1_79_0 $(SRC)/bfs-example.cpp -o $(BLD)/bfs-example

bfs-example2:
	$(CXX) $(CXXFLAGS) -I ~/src/boost_1_79_0 $(SRC)/bfs-example2.cpp -o $(BLD)/bfs-example2

boost_circular_buffer::
	$(CXX) $(CXXFLAGS) -I ~/src/boost_1_79_0 $(SRC)/boost_circular_buffer.cpp -o $(BLD)/boost_circular_buffer

regx_replace1:
	$(CXX) $(CXXFLAGS) $(SRC)/regx_replace1.cpp -o $(BLD)/regx_replace1

regex_replace_example: $(OBJ)/regex_replace_example.o
	$(CXX) $(CXXFLAGS) -I ~/src/boost_1_79_0 $(OBJ)/regex_replace_example.o -o $(BLD)/regex_replace_example

regex_replace_example.o:
	$(CXX) $(CXXFLAGS) -I ~/src/boost_1_79_0 -c $(SRC)/regex_replace_example.cpp -o $(OBJ)/regex_replace_example.o

boost_regex_match:
	$(CXX) $(CXXFLAGS) -I ~/src/boost_1_79_0 $(SRC)/boost_regex_match.cpp -o $(BLD)/boost_regex_match

sample_formats:
	$(CXX) $(CXXFLAGS) -I ~/src/boost_1_79_0 $(SRC)/sample_formats.cpp -o $(BLD)/sample_formats

sample_userType:
	$(CXX) $(CXXFLAGS) -I ~/src/boost_1_79_0 $(SRC)/sample_userType.cpp -o $(BLD)/sample_userType

sub_match:
	$(CXX) $(CXXFLAGS) $(SRC)/sub_match.cpp -o $(BLD)/sub_match

sub_match2:
	$(CXX) $(CXXFLAGS) $(SRC)/sub_match2.cpp -o $(BLD)/sub_match2

dump_ifstream:
	$(CXX) $(CXXFLAGS) $(SRC)/dump_ifstream.cpp $(SRC)/utility.cpp -o $(BLD)/dump_ifstream

map_insert:
	$(CXX) $(CXXFLAGS) $(SRC)/map_insert.cpp -o $(BLD)/map_insert

template_ex1:
	$(CXX) $(CXXFLAGS) $(SRC)/template_ex1.cpp -o $(BLD)/template_ex1

gtk_hello:
	#@echo "MAKE RULE - gtk_hello: disabled"
	gcc $(SRC)/gtk_hello.c -o $(BLD)/gtk_hello `pkg-config --cflags --libs gtk+-3.0`

gtk_example-0:
	@echo "MAKE RULE - gtk_example-0: disabled"
	#gcc `pkg-config --cflags gtk+-3.0` -o $(BLD)/gtk_example-0 $(SRC)/gtk_example-0.c `pkg-config --libs gtk+-3.0`

stl_format:
	$(CXX) $(CXXFLAGS) $(SRC)/stl_format.cpp -o $(BLD)/stl_format

fmtlib.ex1:
	$(CXX) $(CXXFLAGS) $(SRC)/fmtlib.ex1.cpp /usr/local/lib64/libfmt.a -o $(BLD)/fmtlib.ex1

fmtlib.play:
	$(CXX) $(CXXFLAGS) $(SRC)/fmtlib.play.cpp /usr/local/lib64/libfmt.a -o $(BLD)/fmtlib.play

fmtlib.color.ex1.cpp: $(SRC)/fmtlib.color.ex1.cpp
	$(CXX) $(CXXFLAGS) $(SRC)/fmtlib.color.ex1.cpp /usr/local/lib64/libfmt.a -o $(BLD)/fmtlib.color.ex1

string_view_test:
	$(CXX) $(CXXFLAGS) $(SRC)/string_view_test.cpp -o $(BLD)/string_view_test

math_consts:
	$(CXX) $(CXXFLAGS) $(SRC)/math_consts.cpp -o $(BLD)/math_consts

cfilesys:
	$(CC) $(CFLAGS) $(SRC)/cfilesys.c -o $(BLD)/cfilesys

atoi_itoa:
	$(CC) $(CFLAGS) $(SRC)/atoi_itoa.c -o $(BLD)/atoi_itoa

istream:
	$(CXX) $(CXXFLAGS) $(SRC)/istream.cpp -o $(BLD)/istream

threads_ex1:
	$(CXX) $(CXXFLAGS) $(SRC)/threads_ex1.cpp -o $(BLD)/threads_ex1

pipe_timeout:
	gcc $(SRC)/pipe_timeout.c -o $(BLD)/pipe_timeout

signal_ex3:
	gcc $(SRC)/signal_ex3.c -o $(BLD)/signal_ex3

vla_basic:
	gcc $(SRC)/vla_basic.c -o $(BLD)/vla_basic

vla_sizeof:
	gcc $(SRC)/vla_sizeof.c -o $(BLD)/vla_sizeof

vla_pass_vla:
	gcc $(SRC)/vla_pass_vla.c -o $(BLD)/vla_pass_vla

vla_pass_mutivla:
	gcc $(SRC)/vla_pass_mutivla.c -o $(BLD)/vla_pass_mutivla

vla_typedef:
	gcc $(SRC)/vla_typedef.c -o $(BLD)/vla_typedef

itoa_example:
	gcc $(SRC)/itoa_example.c -o $(BLD)/itoa_example

signals_ex1:
	gcc $(SRC)/signals_ex1.c -o $(BLD)/signals_ex1

std_array_ex:
	$(CXX) $(SRC)/std_array_ex.cpp -o $(BLD)/std_array_ex

signals_ex4:
	gcc $(SRC)/signals_ex4.c -o $(BLD)/signals_ex4

std_hex:
	$(CXX) $(SRC)/std_hex.cpp -o $(BLD)/std_hex

std_find_string:
	$(CXX) $(SRC)/std_find_string.cpp -o $(BLD)/std_find_string

std_find:
	$(CXX) $(SRC)/std_find.cpp -o $(BLD)/std_find

dice_unifrom_distribution:
	$(CXX) $(SRC)/dice_unifrom_distribution.cpp -o $(BLD)/dice_unifrom_distribution

get_current_dir:
	$(CXX) $(SRC)/get_current_dir.cpp -o $(BLD)/get_current_dir

stringstream_ex1:
	$(CXX) $(SRC)/stringstream_ex1.cpp -o $(BLD)/stringstream_ex1

constexpr_ex:
	$(CXX) $(SRC)/constexpr_ex.cpp -o $(BLD)/constexpr_ex

char2string:
	$(CXX) $(SRC)/char2string.cpp -o $(BLD)/char2string

filesystem_current_directory:
		$(CXX) $(SRC)/filesystem_current_directory.cpp -o $(BLD)/filesystem_current_directory

stl_set_difference:
		$(CXX) $(SRC)/stl_set_difference.cpp -o $(BLD)/stl_set_difference

eigen_ex1:
		$(CXX) $(SRC)/eigen_ex1.cpp -o $(BLD)/eigen_ex1

strtok:
		$(CXX) $(SRC)/strtok.cpp -o $(BLD)/strtok

regex_search:
		$(CXX) $(SRC)/regex_search.cpp -o $(BLD)/regex_search

unique_ptr_example:
		$(CXX) $(SRC)/unique_ptr_example.cpp -o $(BLD)/unique_ptr_example

regex_example:
	$(CC) $(SRC)/regex_example.cpp -o $(BLD)/regex_example

udpserver_example:
	$(CC) $(SRC)/udpserver_example.c -o $(BLD)/udpserver_example

mybuf:
	$(CXX) $(SRC)/mybuf.cpp -o $(BLD)/mybuf

bit_set_ex1.o:
	$(CXX) $(SRC)/bit_set_ex1.cpp -o $(BLD)/bit_set_ex1

$(BLD)/lambda01: $(OBJ)/lambda01.o
	$(CXX) $(CXXFLAGS) $(OBJ)/lambda01.o -o $(BLD)/lambda01

$(OBJ)/lambda01.o: $(SRC)/lambda01.cpp
	$(CXX) $(CXXFLAGS) -c $(SRC)/lambda01.cpp -o $(OBJ)/lambda01.o


# install man pages
.PHONY: man
man:
	cp ../man/$(APP).1 $(man1dir)
	# gzip $(man1dir)/$(APP).1
	mandb

.PHONY: unman
unman:
	rm $(man1dir)/$(APP).1.gz
	mandb

# install
.PHONY: install
install: man
	cp $(BLD)/$(APP) $(prefix)/bin/$(APP)
	rm $(prefix)/bin/$(APP)

# delete object files & app executable
.PHONY: clean
clean:
	-rm $(BLD)/*
	# -rm -f $(BLD)/$(APP) $(BLD)/*.o $(BLD)/$(APP)_test $(BLD)/bash_color_test
	# -rm -f $(BLD)/*.xml $(BLD)/$(APP).$(BUILD_VERSION).tar.gz
	# -rm -f $(BLD)/std_array
	# -rm -f $(BLD)/read_lines $(BLD)/iter_files $(BLD)/boost_test $(BLD)/regx_replace1
	# -rm -f $(BLD)/sub_match $(BLD)/sub_match2 $(BLD)/dump_ifstream $(BLD)/map_insert
	# -rm -f $(BLD)/gtk_hello
	# -rm -f $(BLD)/gtk_example-0
	# -rm -f $(BLD)/template_ex1
	# -rm -f $(BLD)/string_view_test
	# -rm -f $(BLD)/math_consts
	# -rm -f $(BLD)/faq1.1
	# -rm -f $(BLD)/faq1.2
	# -rm -f $(BLD)/fmtlib.ex1
	# -rm -f $(BLD)/fmtlib.playn
