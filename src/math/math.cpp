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

    unsigned long ret = 1;
    for(int i = 2; i < n+1; ++i)
        ret *= i;
    return ret;
}
