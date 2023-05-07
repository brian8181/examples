// License:    GPL
// Author:     Brian K Preston
// File Name:  iter_time.cpp
// Build Date: Thu May  4 06:47:15 PM CDT 2023
// Version:    0.0.1

#include <iostream>
#include <string>
#include <getopt.h>
#include "main.hpp"
#include "bash_color.h"
#include "iter_time.hpp"
#include <ctime>

using namespace std;

int parse_options(int argc, char* argv[])
{
	int j = 0;
	int len = 3;
	long i = 0;
	long llen = 3l*10l*1000000000l; // 10l*10l*1000l*1000000l;
	time_t beg;
	time_t end;
	time_t diff[len];
	time_t total = 0;

	cout << "Trials: " << len << " Iters: " << llen << endl;

	for(; j < len; ++j)
	{
		beg = time(0);
		for(;i < llen; ++i)
		{
			//cout << i << endl;
		}
		i = 0;
		end = time(0);
		diff[j] = difftime(end, beg);
		total += diff[j];
		cout << beg << " - " << end << " = " << diff[j] << endl;
	}

	double mean = total/len;
	cout << "Total: " << total << endl;
	cout << "Avg: " << mean << endl;

	double run_total = 0;
	for(int k = 0; k < len; ++k)
	{
		double n = (mean - diff[k]);
		run_total += n*n;
	}

	double variance = run_total / len;
	cout << "Variance: " << variance << endl;

	double seconds = mean;
	double minites = seconds / 60;
	double hours = minites / 60;
	double days = hours / 24;
	double weeks = days / 7;
	double years = weeks / 52; 
	cout << "M: " << minites << endl << "D: " << days << days << endl << "W: " << weeks << endl << "Y: " << years << endl;
			
	return 0;
}
