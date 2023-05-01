#include <iostream>
// #include <typeinfo>
// #include <limits>

int main()
{
  float f = 3.f/6.0f;

   std::cout << f << std::endl;


  std::cout << "Enter numbers separated by whitespace (use -1 to quit): ";
  int i = 0;
  while (i != -1) {
    std::cin >> i;        // BAD FORM — See comments below
    std::cout << "You entered " << i << '\n';
  }
  // ...
}