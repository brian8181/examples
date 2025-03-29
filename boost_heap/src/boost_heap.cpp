// License:    GPL
// Author:     Brian K Preston
// File Name:  boost_heap.cpp
// Build Date: Thu May  4 04:34:31 PM CDT 2023
// Version:    0.0.1

#include <iostream>
#include <string>
#include <getopt.h>
#include "main.hpp"
#include "bash_color.h"
#include "boost_heap.hpp"
#include <boost/heap/priority_queue.hpp>

using namespace std;

template <typename PriorityQueue>
void basic_interface(void);

int parse_options(int argc, char* argv[])
{
	cout << FMT_FG_BLUE << "Hello World!"  << FMT_RESET << endl;
	cout << FMT_FG_RED << "Hello World!"  << FMT_RESET << endl;
	cout << FMT_FG_GREEN << "Hello World!"  << FMT_RESET << endl;
	cout << FMT_FG_YELLOW << "Hello World!"  << FMT_RESET << endl;
	
	return 0;
}

// PriorityQueue is expected to be a max-heap of integer values
template <typename PriorityQueue>
void basic_interface(void)
{
    PriorityQueue pq;

    pq.push(2);
    pq.push(3);
    pq.push(1);

    cout << "Priority Queue: popped elements" << endl;
    cout << pq.top() << " "; // 3
    pq.pop();
    cout << pq.top() << " "; // 2
    pq.pop();
    cout << pq.top() << " "; // 1
    pq.pop();
    cout << endl;
}
