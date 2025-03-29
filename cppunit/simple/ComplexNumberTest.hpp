
#ifndef _ComplexNumberTest_H
#define _ComplexNumberTest_H

#include <cppunit/Test.h>
#include <cppunit/TestCase.h>
#include "Complex.hpp"

class ComplexNumberTest : public CppUnit::TestCase 
{ 
public: 

    ComplexNumberTest( std::string name ) : CppUnit::TestCase( name ) 
    {
    }

    void runTest()
    {
        CPPUNIT_ASSERT( Complex (10, 1) == Complex (10, 1) );
        CPPUNIT_ASSERT( !(Complex (1, 1) == Complex (2, 2)) );
    }
};

#endif