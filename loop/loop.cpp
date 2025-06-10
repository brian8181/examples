//    File:    makefile
//    Date:    Sun Dec 15 05:46:02 PM CST 2024
// Version:    0.0.1

#include <stdlib.h>
#include <unistd.h>         /* for STDIN_FILENO */
#include <sys/select.h>     /* for pselect   */
#include <getopt.h>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <math.h>
#include "bash_color.hpp"

using std::string;
using std::stringstream;
using std::vector;
using std::cout;
using std::cerr;
using std::endl;

const string VERSION_STRING = "0.0.1";
const int DEFAULT_ARGC = 0;
const unsigned short VERBOSE          = 0x01;
const unsigned short DEFAULTS         = 0x00;
const unsigned short FIELDS           = 0x02;
unsigned short options = DEFAULTS;
char DELIMITER = ',';

static struct option long_options[] =
{
        {"verbose", no_argument, 0, 'v'},
        {"help", no_argument, 0, 'h'},
        {"version", no_argument, 0, 'r'},
};

unsigned short OPTION_FLAGS = DEFAULTS;

void print_version()
{
	cout << VERSION_STRING << endl;
}

void print_help()
{
	cout	<< endl
			<< FMT_BOLD      << FMT_FG_GREEN << "Usage: " << FMT_RESET << endl
			<< FMT_BOLD      << /*~ "${APP_NAME}"         << ~*/ FMT_RESET << " "
			<< FMT_FG_BLUE   << "[-hvr][...]"             << FMT_RESET << " "
         												  <<  endl << endl;
}

int parse_options(int argc, char* argv[])
{
	int opt = 0;
	int option_index = 0;
	optind = 0;
	while ((opt = getopt_long(argc, argv, "hv ", long_options, &option_index)) != -1)
	{
		switch (opt)
		{
			case 'h':
				print_help();
			case 'v':
				print_version();
				return 0;
		}
	}

	if (argc < DEFAULT_ARGC) // not correct number of args
	{
		cerr << "Expected argument after options, -h for help" << endl;
		return -1;
	}

	string path = argv[0];   // get exe file path
	cout << argv[0] << endl;

	return 0;
}

int stdin_ready (int filedes)
{
	//
	return 0;
}

void print_digits(const int& n)
{
	const int dim = 10;
	//const int len = dim*dim*dim*dim;

	stringstream ss;

	ss << std::endl << "base = " << dim <<  " : n = " << n << std::endl;

	int x = (n / (dim*dim*dim));    // trim 3 digits off right                     : 1234 -> 1
	int y = (n / (dim*dim) % dim);  // trim 2 digits off right & then one off left : 1234 -> 2
	int z = ((n / dim) % dim);      // trim 2 digits off left & one off right      : 1234 -> 3
	int t = (n % dim);              // trim 3 off left                             : 1234 -> 4

	ss << '\t' << x << "," << y << "," << z << "," << t << "=" << x*y*z*t << std::endl;
	cout << ss.str();
}

int main(int argc, char* argv[])
{
	const int dim = 10;
	const int len = dim*dim*dim*dim;

	stringstream ss;
	for(int i = 0; i < len; ++i)
	{
		int x = ((((i / dim) / dim) / dim) / dim)+1;          // trim 3 digits off right                    : 1234 -> 1
		int y = (((((i / dim) / dim) / dim) / dim) % dim)+1;  // trim 2 digit off right & then 1 off left  : 1234 -> 2
		int z = (((i / dim) / dim) % dim)+1;                  // trim 2 digits off left 2 off right        : 1234 -> 3
		int t = (i % dim)+1;                                  // trim 3 digits off left                     : 1234 -> 4

		if( t == 1 )
		{
			ss << endl;
		}
		ss << '\t' << x << "," << y << "," << z << "," << t << "=" << x*y*z*t;
	}

	cout << ss.str();

	const int n = 1234;
	print_digits(n);
	const int n2 = 9876;
	print_digits(n2);
}
