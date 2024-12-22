class Complex { 
  friend bool operator ==(const Complex& a, const Complex& b);
  double real, imaginary;
public:
  Complex( double r, double i = 0 ) 
    : real(r)
        , imaginary(i) 
  {
  }
};

bool operator ==( const Complex &a, const Complex &b )
{ 
  return eq( a.real, b.real )  &&  eq( a.imaginary, b.imaginary ); 
}