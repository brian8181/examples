#include <string.h>
#include <stdio.h>
#include <list>
#include <iostream>
#include <string>


using namespace std;

template <typename Container>
void
stringtok(Container &container, string const &in,
	  const char * const delimiters = " \t\n")
{
    const string::size_type len = in.length();
	  string::size_type i = 0;

    while (i < len)
    {
	// Eat leading whitespace
	i = in.find_first_not_of(delimiters, i);
	if (i == string::npos)
	  return;   // Nothing left but white space

	// Find the end of the token
	string::size_type j = in.find_first_of(delimiters, i);

	// Push token
	if (j == string::npos)
	{
	  container.push_back(in.substr(i));
	  return;
	}
	else
	  container.push_back(in.substr(i, j-i));

	// Set up for next loop
	i = j + 1;
    }
}

int main()
{
    std::list<string>  ls;
    stringtok (ls, " this  \t is\t\n  a test  ");
    for(auto i = ls.begin(); i != ls.end(); ++i)
    {
        std::cerr << ':' << (*i) << ":\n";
    } 
}