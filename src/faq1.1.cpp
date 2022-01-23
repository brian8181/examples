#include <iostream>
int main()
{
  std::cout << "Enter numbers separated by whitespace (use -1 to quit): ";
  int i = 0;
  while (i != -1) {
    std::cin >> i;        // BAD FORM — See comments below
    std::cout << "You entered " << i << '\n';
  }
  // ...
}