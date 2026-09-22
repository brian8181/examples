# @name     pipewire1
# @file:    makefile
# @date:    Tue Sep 22 02:38:52 AM EDT 2026
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

APP=pipewire1
CXX=g++
CXXFLAGS=-g -Wall -std=c++17
CXXEXTRA=-Wno-template-body
CXXCPP=
LDFLAGS=
LIBS=

SRC = src
BLD = build
OBJ = build
TST = build

# # Define your directories as a clean space-separated list
# INCDIRS := /one /two /three/four

# # Automatically turn them into -I/one -I/two -I/three/four
# CFLAGS  := $(addprefix -I,$(INCDIRS))

# lib settings
LIBS=-L/usr/lib -L/usr/lib64 -L/usr/local/lib -L/usr/local/lib64 #-L/home/brian/src/pipewire/builddir/src/pipewire/libpipewire-0.3.so
INCLUDES=-I/usr/local/include/cppunit/ -I/home/brian/src/pipewire/src -I/home/brian/src/pipewire/spa/include -I/home/brian/src/pipewire/builddir/src
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

all: $(BLD)/pipewire1 $(BLD)/libpipewire1.so $(BLD)/libpipewire1.a $(BLD)/TEST_pipewire1 #

$(BLD)/test1: src/test1.c
	$(CXX) $(CXXFLAGS) $(LDFLAGS) src/test1.c /home/brian/src/pipewire/builddir/src/pipewire/libpipewire-0.3.so -o $(BLD)/test1

$(BLD)/pipewire1: $(OBJ)/main.o $(OBJ)/pipewire1.o
	 $(CXX) $(CXXFLAGS) $(OBJ)/main.o $(OBJ)/pipewire1.o -o $(BLD)/pipewire1 #

$(BLD)/libpipewire1.so: $(OBJ)/main.o $(BLD)/pipewire1.o
	$(CXX) $(CXXFLAGS) $(CXXEXTRA) --shared $(OBJ)/main.o $(BLD)/pipewire1.o -o $(BLD)/libpipewire1.so
	-chmod 755 $(BLD)/libpipewire1.so

$(BLD)/libpipewire1.a: $(OBJ)/main.o $(BLD)/pipewire1.o
	-ar rvs $(BLD)/libpipewire1.a $(OBJ)/main.o $(BLD)/pipewire1.o
	-chmod 755 $(BLD)/libpipewire1.a

$(OBJ)/pipewire1.o: $(SRC)/pipewire1.cpp
	$(CXX) $(CXXFLAGS) $(CXXEXTRA) -c $(SRC)/pipewire1.cpp -o $(OBJ)/pipewire1.o

$(BLD)/TEST_pipewire1: $(OBJ)/pipewire1.o $(OBJ)/TEST_pipewire1.o
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
	cp ./$(BLD)/pipewire1 ./$(prefix)/bin/pipewire1
uninstall:
	-rm ./$(prefix)/bin/pipewire1
clean:
	@echo "removing files ..."
	-rm -f $(OBJ)/*
	-rm -f $(BLD)/*

help:
	@echo
	@echo  'Project: pipewire1 : version 0.0.1 : Tue Sep 22 02:38:52 AM EDT 2026 simple "pipewire1" framework.'
	@echo
	@echo  '    make [-f] [target]'
	@echo
	@echo  '   -Make Targets ...'
	@echo
	@echo  '        * all                              - build all'
	@echo  '        * $(BLD)/pipewire1:          - re/build pipewire1'
	@echo  '        * $(BLD)/pipewire1_utest:    - re/build pipewire1_utest, unit testing'
	@echo  '        * clean                            - remove most generated files but keep the config'
	@echo
