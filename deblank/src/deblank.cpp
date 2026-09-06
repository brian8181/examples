/**
 * @file    deblank.hpp
 * @version version 0.0.1
 * @date    Sat, 05 Sep 2026 10:41:38 +0000
 */
#include <iostream>
#include <chrono> // Required header
#include <thread> // Used here just to simulate work (sleep)
#include <getopt.h>
#include <cstring>
#include "fileio.hpp"
#include "deblank.hpp"
#include "bash_color.hpp"

using std::string;
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

void get_time(char* str);
void deblank(char* str);
void deblank2(char* str);

void print_version()
{
	cout << VERSION_STRING << endl;
}

void print_help()
{
	cout	<< endl
			<< FMT_BOLD      << FMT_FG_GREEN << "Usage: " << FMT_RESET << endl
			<< FMT_BOLD      << " $APP_NAME " << FMT_RESET << " "
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

	string s;
	read_str(argv[1], s);
	string str1 = s;
	string str2 = s;
	char* v1 = str1.data();
	char* v2 = str2.data();

	get_time(v1);
	get_time(v2);

	// cout << "ver1 = " << v1 << endl;
	// cout << "ver2 = " << v2 << endl;

	return 0;
}

void get_time(char* str)
{
	auto start = std::chrono::steady_clock::now();
	// --- Place the code you want to measure here ---
	deblank(str);
	std::this_thread::sleep_for(std::chrono::milliseconds(500));
	// -----------------------------------------------
	// 2. Record the ending time point
	auto end = std::chrono::steady_clock::now();
	// 3. Calculate the difference (duration)
	auto elapsed = end - start;
	// 4. Convert and print the duration in your preferred unit
	// Example: Milliseconds
	auto elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(elapsed).count();
	// Example: Microseconds
	auto elapsed_us = std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count();
	std::cout << "Elapsed time: " << elapsed_ms << " ms\n";
	std::cout << "Elapsed time: " << elapsed_us << " us\n";
}
void deblank(char* str)
{
	int len = static_cast<int>(std::strlen(str));
	int i = 0;
	for(int offset = 0; offset < len; ++offset)
	{
		if(str[offset] == ' ')
			continue;
		str[i] = str[offset];
		++i;
	}
	str[i] = '\0';
}

void deblank2(char* str)
{
	int len = static_cast<int>(std::strlen(str));
	int i = 0;
	for(int offset = 0; offset < len; ++offset)
	{
		if(str[offset] == ' ')
			continue;
		if (i != offset)
			str[i] = str[offset];
		++i;
	}
	str[i] = '\0';
}
