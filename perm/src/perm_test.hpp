/**
 * @file    perm_test.hpp
 * @version 0.0.1
 * @date    Sun, 05 Apr 2026 14:35:04 +0000
 * @info    ...
 */
#ifndef _TEST_perm_test_H
#define _TEST_perm_test_H

#include <cppunit/Test.h>

class TEST_perm_test : public CppUnit::TestFixture
{
private:
    CPPUNIT_TEST_SUITE(TEST_perm_test);
    CPPUNIT_TEST(testNoOptions);
    CPPUNIT_TEST(testOptionHelp);
    CPPUNIT_TEST(testOptionHelpLong);
    CPPUNIT_TEST(testOptionVerbose);
    CPPUNIT_TEST(testOptionVerboseLong);
    CPPUNIT_TEST_SUITE_END();

public:
    void setUp();
    void tearDown();

    // agregate test functions
    void execute();
    void execute(int argc, char* argv[]);

protected:
    void testNoOptions();
    void testOptionHelp();
    void testOptionHelpLong();
    void testOptionVerbose();
    void testOptionVerboseLong();

private:
    int m_argc;
    char* m_argv[10];

};

#endif
