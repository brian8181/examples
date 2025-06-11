# File Name:  pascal_triangle/makefile
# Build Date: Wed Apr 23 22:44:01 CDT 2025
# Version:    0.1.1

APP=pascal_triangle
CXX=g++
CXXFLAGS=-Wall -std=c++20 -fPIC -g
SRC=src
BLD?=build
OBJ?=build

# lib settings
LDFLAGS = -static -lcppunit -L/usr/local/lib/
INCLUDES = -I/usr/local/include/cppunit/

ifdef DEBUG
	CXXFLAGS +=-g -DDEBUG
endif

ifdef CYGWIN
	CXXFLAGS += -DCYGWIN
endif

all: ./$(BLD)/pascal_triangle ./$(BLD)/libpascal_triangle.so ./$(BLD)/libpascal_triangle.a

rebuild: clean all

./$(BLD)/pascal_triangle: ./$(OBJ)/pascal_triangle.o #CCSK_PREREQUISTE#
	 $(CXX) $(CXXFLAGS) -o ./$(BLD)/pascal_triangle ./$(OBJ)/pascal_triangle.o #CCSK_PREREQUISTE#

#./$(BLD)/pascal_triangle_test: ./$(OBJ)/pascal_triangle_test.o #CCSK_PREREQUISTE#
#	 $(CXX) $(CXXFLAGS) -o ./$(BLD)/pascal_triangle_test ./$(OBJ)/pascal_triangle_test.o #CCSK_PREREQUISTE#

./$(BLD)/libpascal_triangle.so: ./$(BLD)/pascal_triangle.o
	$(CXX) $(CXXFLAGS) $(CXXEXTRA) --shared ./$(BLD)/pascal_triangle.o -o ./$(BLD)/libpascal_triangle.so
	-chmod 755 ./$(BLD)/libpascal_triangle.so

./$(BLD)/libpascal_triangle.a: ./$(BLD)/pascal_triangle.o
	-ar rvs ./$(BLD)/libpascal_triangle.a ./$(BLD)/pascal_triangle.o
	-chmod 755 ./$(BLD)/libpascal_triangle.a

./$(OBJ)/%.o: ./$(SRC)/%.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

#CCSK_RULE#

.PHONY: install
install:
	cp ./$(BLD)/pascal_triangle ./$(prefix)/bin/pascal_triangle

.PHONY: uninstall
uninstall:
	-rm ./$(prefix)/bin/pascal_triangle

.PHONY: clean
clean:
	-rm -f ./$(OBJ)/*.o
	-rm -f ./$(BLD)/*.o
	-rm -f ./$(BLD)/pascal_triangle*


.PHONY: help
help:
	@echo  '  all         - build all'
	@echo  '  pascal_triangle          - build pascal_triangle executable'
	@echo  '  pascal_triangle.o        - build not link'
	@echo  '  pascal_triangle_test     - build cppunit test'
	@echo  '  pascal_triangle_test.o   - build cppunit test'
	@echo  '  clean                      - remove all files from build dir'
	@echo  '  install                    - copy files to usr/local'
	@echo  '  dist                       - create distribution, tar.gz'
