# @name     deblank
# @file:    makefile
# @date:    Sat Sep  5 06:41:37 AM EDT 2026
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
GREEN=\033[32m
RESET=\033[0m

APP=deblank
CXX=g++
CXXFLAGS=-Wall -std=c++20 -fPIC -save-temps 
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
	LDFLAGS += -lcppunit.dll
else
	LDFLAGS += -lcppunit
endif

all: $(BLD)/deblank $(BLD)/libdeblank.so $(BLD)/libdeblank.a $(BLD)/TEST_deblank #

$(BLD)/deblank: $(OBJ)/main.o $(OBJ)/deblank.o $(OBJ)/fileio.o
	@echo -e "$(GREEN)Target -> \"$@: $^$(RESET)"
	$(CXX) $(CXXFLAGS) $^ -o $@

$(BLD)/libdeblank.so: $(OBJ)/main.o $(BLD)/deblank.o
	@echo -e "$(GREEN)Target -> \"$@: $^$(RESET)"
	$(CXX) $(CXXFLAGS) $(CXXEXTRA) --shared $(OBJ)/main.o $(BLD)/deblank.o -o $(BLD)/libdeblank.so
	-chmod 755 $(BLD)/libdeblank.so

$(BLD)/libdeblank.a: $(OBJ)/main.o $(BLD)/deblank.o
	@echo -e "$(GREEN)Target -> \"$@: $^$(RESET)"
	-ar rvs $(BLD)/libdeblank.a $(OBJ)/main.o $(BLD)/deblank.o
	-chmod 755 $(BLD)/libdeblank.a

$(OBJ)/deblank.o: $(SRC)/deblank.cpp
	@echo -e "$(GREEN)Target -> \"$@: $^$(RESET)"
	$(CXX) $(CXXFLAGS) $(CXXEXTRA) -c $(SRC)/deblank.cpp -o $(OBJ)/deblank.o

$(BLD)/TEST_deblank: $(OBJ)/deblank.o $(OBJ)/TEST_deblank.o
	@echo -e "$(GREEN)Target -> \"$@: $^$(RESET)"
	$(CXX) $(CXXFLAGS) $^ $(LDFLAGS) -o $@

# rules <?= "\nTEST\n ?>
# copy header to build dir
$(BLD)/%.hpp: $(SRC)/%.hpp
	@echo -e "$(GREEN)Target -> \"$@: $^$(RESET)"
	-cp $^ $@

$(OBJ)/%.o: ./$(SRC)/%.cpp
	@echo -e "$(GREEN)Target -> \"$@: $^$(RESET)"
	$(CXX) $(CXXFLAGS) -c -o $@ $<

#
.PHONY: all clean install unintsall rebuild help

rebuild: clean all

install:
	cp ./$(BLD)/deblank ./$(prefix)/bin/deblank
uninstall:
	-rm ./$(prefix)/bin/deblank
clean:
	@echo "removing files ..."
	-rm -f $(OBJ)/*
	-rm -f $(BLD)/*

help:
	@echo
	@echo  'Project: deblank : version 0.0.1 : Sat Sep  5 06:41:37 AM EDT 2026 simple "deblank" framework.'
	@echo
	@echo  '    make [-f] [target]'
	@echo
	@echo  '   -Make Targets ...'
	@echo
	@echo  '        * all                              - build all'
	@echo  '        * $(BLD)/deblank:          - re/build deblank'
	@echo  '        * $(BLD)/deblank_utest:    - re/build deblank_utest, unit testing'
	@echo  '        * clean                            - remove most generated files but keep the config'
	@echo
