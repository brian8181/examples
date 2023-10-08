// CPP program to get a string from single
// character.
#include <iostream>
#include<bits/stdc++.h>
using namespace std;
 
string getString(char x)
{
    // string class has a constructor
    // that allows us to specify size of
    // string as first parameter and character
    // to be filled in given size as second
    // parameter.
    string s(1, x);
 
    return s;   
}
 
int main() {
  cout << getString('a') << endl;
  return 0;
}