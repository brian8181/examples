/**
 * @file    pipewire1.hpp
 * @version 0.0.1
 * @date    Tue, 22 Sep 2026 06:38:52 +0000
 */
#ifndef _TEST_pipewire1_H
#define _TEST_pipewire1_H

#include <cppunit/Test.h>

class TEST_pipewire1 : public CppUnit::TestFixture
{
private:
    CPPUNIT_TEST_SUITE(TEST_pipewire1);
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
