# @name     perm
# @file:    makefile
# @date:    Sun Apr  5 09:35:03 CDT 2026
# @version: version 0.0.1

# g++ warnings
#-Wall -Wextra -Wpedantic -Wshadow -Wconversion -Werror -Wundef
#-fsanitize=undefined,address -Wfloat-equal -Wformat-nonliteral
#-Wformat-security -Wformat-y2k -Wformat=2 -Wimport -Winvalid-pch
#-Wlogical-op -Wmissing-declarations -Wmissing-field-initializers
#-Wmissing-format-attribute -Wmissing-include-dirs -Wmissing-noreturn
#-Wnested-externs -Wpacked -Wpointer-arith -Wredundant-decls
#-Wstack-protector -Wstrict-null-sentinel -Wswitch-enum -Wwrite-strings

SHELL:=bash

APP=perm
CXX=g++
CXXFLAGS=-Wall -std=c++20 -fPIC
CXXEXTRA=-Wno-template-body
CXXCPP=
LDFLAGS=
LIBS=

SRC = src
BLD = build
OBJ = build
TST = build

# lib settings
LIBS=-L/usr/lib -L/usr/lib64 -L/usr/local/lib -L/usr/local/lib64
INCLUDES=-I/usr/local/include/cppunit/
LDFLAGS=$(INCLUDES) $(LIBS)

ifndef RELEASE
	CXXFLAGS +=-g -DDEBUG
endif

ifdef CYGWIN
	CXXFLAGS +=-DCYGWIN
	LDFLAGS += -lfmt -lcppunit.dll
else
	LDFLAGS += -lfmt -lcppunit
endif

all: $(BLD)/perm $(BLD)/libperm.so $(BLD)/libperm.a

$(BLD)/perm: $(OBJ)/main.o $(OBJ)/perm.o
	 $(CXX) $(CXXFLAGS) $(OBJ)/main.o $(OBJ)/perm.o -o $(BLD)/perm
$(BLD)/libperm.so: $(OBJ)/main.o $(BLD)/perm.o
	$(CXX) $(CXXFLAGS) $(CXXEXTRA) --shared $(OBJ)/main.o $(BLD)/perm.o -o $(BLD)/libperm.so
	-chmod 755 $(BLD)/libperm.so

$(BLD)/libperm.a: $(OBJ)/main.o $(BLD)/perm.o
	-ar rvs $(BLD)/libperm.a $(OBJ)/main.o $(BLD)/perm.o
	-chmod 755 $(BLD)/libperm.a

$(OBJ)/perm.o: $(SRC)/perm.cpp
	$(CXX) $(CXXFLAGS) $(CXXEXTRA) -c $(SRC)/perm.cpp -o $(OBJ)/perm.o

$(BLD)/perm_test: $(SRC)/perm_test.cpp
	$(CXX) $(CXXFLAGS) $^ $(LDFLAGS) -o $@

# rules <?= "\nTEST\n ?>
# copy header to build dir
$(BLD)/%.hpp: $(SRC)/%.hpp
	-cp $^ $@

$(OBJ)/%.o: ./$(SRC)/%.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

#
.PHONY: all clean install unintsall rebuild help

rebuild: clean all

install:
	cp ./$(BLD)/perm ./$(prefix)/bin/perm
uninstall:
	-rm ./$(prefix)/bin/perm
clean:
	@ECHO "removing files ..."
	-rm -f $(OBJ)/*
	-rm -f $(BLD)/*

help:
	@echo
	@echo  'Project: perm : version 0.0.1 : Sun Apr  5 09:35:03 CDT 2026 simple "perm" framework.'
	@echo
	@echo  '    make [-f] [target]'
	@echo
	@echo  '   -Make Targets ...'
	@echo
	@echo  '        * all                              - build all'
	@echo  '        * $(BLD)/perm:          - re/build perm'
	@echo  '        * $(BLD)/perm_utest:    - re/build perm_utest, unit testing'
	@echo  '        * clean                            - remove most generated files but keep the config'
	@echo
