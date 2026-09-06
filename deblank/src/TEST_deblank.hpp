/**
 * @file    deblank.hpp
 * @version 0.0.1
 * @date    Sat, 05 Sep 2026 10:41:38 +0000
 */
#ifndef _TEST_deblank_H
#define _TEST_deblank_H

#include <cppunit/Test.h>

class TEST_deblank : public CppUnit::TestFixture
{
private:
    CPPUNIT_TEST_SUITE(TEST_deblank);
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
