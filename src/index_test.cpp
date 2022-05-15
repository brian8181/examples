#include <iostream>

int main(int argc, char* argv[])
{
    int a[5];
    int* p = &a[0];
    (p+2)[1] = 2;
    std::cout << *p << std::endl;

    
}