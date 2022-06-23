#include <iostream>
#include <cmath>

using namespace std;

double exp(double n)
{
    int m = 8;
    return 0;
}

unsigned long factorial(unsigned long n)
{
    if(n > 10)
    {
        cerr << "input 'n' too large ..." << endl;
        return 0;
    }

    unsigned long ret = 0;
    for(int i = 1; i < n+1; ++i)
        ret *= i;
    return ret;
}
