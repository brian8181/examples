#include <iostream>
#include <sstream>
#include <string>
#include <regex>
#include <getopt.h>
#include "main.hpp"
#include "istream.hpp"

using namespace std;

int parse_options(int argc, char* argv[])
{
	
	char c[10] = {};
	std::istringstream input("This is sample text."); // std::stringbuf makes its entire
	input.readsome(c, 5);
	cout << c;

	std::ostringstream out;
	out << "ONE" << endl << "TWO" << endl << "THREE" << endl;
	cout << out.str();

	return 0;
}
