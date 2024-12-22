// #include <cppunit/extensions/TestFactoryRegistry.h>
// #include <cppunit/ui/text/TestRunner.h>
// #include <cppunit/TestSuite.h>
// #include "ComplexNumberTest.hpp"

// int main( int argc, char **argv)
// {
//   CppUnit::TextUi::TestRunner runner;
//   runner.addTest( ComplexNumberTest::suite() );
//   runner.run();
//   return 0;
// }


#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/ui/text/TestRunner.h>
#include "ComplexNumberTest.hpp"

int main( int argc, char **argv)
{
  
  CppUnit::TextUi::TestRunner runner;
  CppUnit::TestFactoryRegistry &registry = CppUnit::TestFactoryRegistry::getRegistry();
  runner.addTest( registry.makeTest() );
  bool wasSucessful = runner.run( "", false );
  return wasSucessful;

}