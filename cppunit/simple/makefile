CXX=g++
CXXFLAGS=-g -DDEBUG -fPIC
LDFLAGS=-static -lcppunit -L/usr/local/lib/
INCLUDES=-I/usr/local/include/cppunit/


all: bin/ComplexNumberTest

bin/ComplexNumberTest: Complex.cpp ComplexNumberTest.cpp main.cpp  
 	$(CXX) $(CXXFLAGS) $(LDFLAGS) $(INCLUDES) Complex.cpp ComplexNumberTest.cpp main.cpp -o bin/ComplexNumberTest

# bin/ComplexNumberTest: main.cpp obj/ComplexNumberTest.o 
# 	$(CXX) $(CXXFLAGS) $(LDFLAGS) $(INCLUDES) main.cpp obj/ComplexNumberTest.o -lcppunit -o bin/ComplexNumberTest

# obj/ComplexNumberTest.o: ComplexNumberTest.cpp obj/Complex.o
# 	$(CXX) $(CXXFLAGS) $(LDFLAGS) $(INCLUDES) -c ComplexNumberTest.cpp obj/Complex.o -o obj/ComplexNumberTest.o

# obj/Complex.o: Complex.cpp
# 	$(CXX) $(CXXFLAGS) -c Complex.cpp -o obj/Complex.o

.PHONY: clean
clean:
	-rm -f ./obj/*
	-rm -f ./bin/*