class ComplexNumberTest : public CppUnit::TestFixture  {
private:
  Complex *m_10_1, *m_1_1, *m_11_2;

protected:
  void setUp()
  {
    m_10_1 = new Complex( 10, 1 );
    m_1_1 = new Complex( 1, 1 );
    m_11_2 = new Complex( 11, 2 );  
  }

  void tearDown() 
  {
    delete m_10_1;
    delete m_1_1;
    delete m_11_2;
  }

  void testEquality()
  {
    CPPUNIT_ASSERT( *m_10_1 == *m_10_1 );
    CPPUNIT_ASSERT( !(*m_10_1 == *m_11_2) );
  }

  void testAddition()
  {
    CPPUNIT_ASSERT( *m_10_1 + *m_1_1 == *m_11_2 );
  }

    CPPUNIT_TEST_SUITE( ComplexNumberTest );
    // [...]
    CPPUNIT_TEST_EXCEPTION( testDivideByZeroThrows, MathException );
    CPPUNIT_TEST_SUITE_END();

// [...]

  void testDivideByZeroThrows()
  {
    // The following line should throw a MathException.
    *m_10_1 / ComplexNumber(0);
  }
};