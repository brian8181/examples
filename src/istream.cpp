#include <iostream>
#include <sstream>
#include <string>
#include <regex>
#include <getopt.h>

using namespace std;

int main(int argc, char* argv[])
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
