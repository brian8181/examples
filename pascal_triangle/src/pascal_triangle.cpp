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
			<< FMT_BOLD      << "/*~${APP_NAME}~*/" << FMT_RESET << " "
			<< FMT_FG_BLUE   << "[-hvr][...]"             << FMT_RESET << " "
         												  <<  endl << endl;
}

string print_coffs(int n)
{
	std::vector< std::vector<int> > triangle = { {1,1} };
	for(int i = 1; i < n; ++i)
	{
		int len = triangle[i-1].size();
		std::vector<int> next(len + 1);
		next[0] = 1;
		for(int j = 1; j < len; ++j)
		{
		 	next[j] = triangle[i-1][j-1] + triangle[i-1][j];
		}
		next[len] = 1; 
		triangle.push_back(next);
	}

	stringstream ss;
	int nlen = triangle[n-1].size();
	int j = 0;
	for(; j < nlen; ++j)
	{
		int y = j;
		int x = nlen - (j+1);
		ss << triangle[n-1][j] << ".*x.^" << x << ".*y.^" << y << " + ";
	}
	string s = ss.str();
	s.resize(s.size()-2);
	cout << s << std::endl;

	return s;
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

	if(argc < 2)
		return 0;

	std::vector< std::vector<int> > triangle = { {1,1} };
			
	int rows = atoi( argv[1] );
	for(int i = 1; i < rows; ++i)
	{
		int len = triangle[i-1].size();
		std::vector<int> next(len + 1);
		next[0] = 1;
		for(int j = 1; j < len; ++j)
		{
		 	next[j] = triangle[i-1][j-1] + triangle[i-1][j];
		}
		next[len] = 1; 
		triangle.push_back(next);
	}

	int mlen = triangle.size();
	for(int i = 0; i < mlen; ++i)
	{
	 	int nlen = triangle[i].size();
	 	int j = 0;
	 	for(; j < nlen; ++j)
	 	{
			int y = j;
			int x = nlen - (j+1);
	 		cout << triangle[i][j] << ".*x.^" << x << ".*y.^" << y << " + ";
	 	}
		cout << std::endl;
	}

	if(argc > 2)
		print_coffs( atoi(argv[2]) );
	return 0;
}

int stdin_ready (int filedes)
{
	// initialize the file descriptor set
	fd_set set;
	FD_ZERO(&set);
	FD_SET(filedes, &set);
#ifndef CYGWIN
	// declare/initialize timespec
	struct timespec timeout = { .tv_sec = 0 };
	return pselect(filedes + 1, &set, NULL, NULL, &timeout, NULL);
#else
	// declare/initialize timeout
	struct timeval timeout = { .tv_sec = 0 };
	return select(filedes + 1, &set, NULL, NULL, &timeout);
#endif
}

int main(int argc, char* argv[])
{
	try
	{
		if(stdin_ready(STDIN_FILENO))
		{
			std::string buffer;
			std::cin >> buffer;
			// add piped buffer to end of argv
			char* argvtmp[sizeof(char*) * argc+1];
			memcpy(argvtmp, argv, sizeof(char*) * argc);
			argvtmp[argc] = &buffer[0];
			argv = argvtmp;
			++argc;
		}
		return parse_options(argc, argv);
	}
	catch(std::logic_error& ex)
	{
	 	std::cout << ex.what() << std::endl;
	}
}