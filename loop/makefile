# File:  ./makefile
# Date: Wed Apr 16 14:30:35 CDT 2025
# Version:    0.1.0

CXX=g++
CXXFLAGS=-Wall -std=c++17
CXXEXTRA=-fPIC
APP_NAME=loop
BLD=build
OBJ=build
SRC=src
DEBUG=1

ifdef DEBUG
	CXXFLAGS += -g -DDEBUG
endif

all: $(BLD)/loop $(BLD)/libloop.so $(BLD)/libloop.a 

$(BLD):
	-echo testing ...
	#-if not exist $(BLD) mkdir "./$(BLD)"
	exit 1

$(BLD)/loop: $(OBJ)/loop.o #CCSK_PREREQUISTE#
	 $(CXX) $(CXXFLAGS) -o $(BLD)/loop $(OBJ)/loop.o #CCSK_PREREQUISTE#

$(BLD)/libloop.so: $(BLD)/loop.o
	$(CXX) $(CXXFLAGS) $(CXXEXTRA) --shared $(BLD)/loop.o -o $(BLD)/libloop.so
	-chmod 755 $(BLD)/libloop.so

$(BLD)/libloop.a: $(BLD)/loop.o
	-ar rvs $(BLD)/libloop.a $(BLD)/loop.o
	-chmod 755 $(BLD)/libloop.a

$(OBJ)/loop.o: $(SRC)/loop.cpp
	$(CXX) $(CXXFLAGS) $(CXXEXTRA) -c $(SRC)/loop.cpp -o $(OBJ)/loop.o

#CCSK_RULE#

.PHONY: all clean
clean:
	-rm -f $(OBJ)/*.
	-rm -f $(BLD)/*
