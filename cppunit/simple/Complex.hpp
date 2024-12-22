#ifndef _Complex_H
#define _Complex_H

class Complex 
{ 
public:

    Complex( double r, double i = 0 ) : real(r), imaginary(i) 
    {
    }

    friend bool operator==( const Complex& a, const Complex& b );    

private:

    double real;
    double imaginary;
};

#endif