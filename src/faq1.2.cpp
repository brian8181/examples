#include <iostream>
int main()
{
  std::cout << "Enter a number, or -1 to quit: ";
  int i = 0;
  while (std::cin >> i) {    // GOOD FORM
    if (i == -1) break;
    std::cout << "You entered " << i << '\n';
  }
  // ...
}