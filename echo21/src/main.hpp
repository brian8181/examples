#ifndef _STD_HPP
#define _STD_HPP

#include <string>
#include <getopt.h>
#include "bash_color.h"
#include <vector>


using namespace std;

// functions
void print_help();
void print_match_header(const string& pattern, const string& src, const bool single_flag, const bool pretty_flag);
//int parse_options(int argc, char* argv[]);
int parse_options(vector<string> argv);

#endif
