// File Name:  fileio.cpp
// Build Date: Sat Nov 25 06:03:48 AM CST 2023
// Version:    3.6.7

#include <iostream>
#include <fstream>
#include <algorithm>
#include <sstream>
#include <string>
#include "fileio.hpp"

using std::stringstream;
using std::ifstream;
using std::ofstream;
using std::pair;
using std::ios;

ifstream& read_char(ifstream& stream, /* out */ char& c)
{
    if (stream.is_open())
    {
        stream.get(c);
        if (!stream)
        {
            std::cerr << "Error: Unable to read character." << std::endl;
            exit(-1);
        }
    }
    else
    {
        std::cerr << "Error: Unable to open file for reading character." << std::endl;
    }
    return stream;
}

ofstream& write_char(ofstream& stream, /* in */ const char& c)
{
    if (stream.is_open())
    {
        stream.put(c);
        if (!stream)
        {
            std::cerr << "Error: Unable to write character." << std::endl;
            exit(-1);
        }
    }
    else
    {
        std::cerr << "Error: Unable to open file for writing character." << std::endl;

    }
    return stream;
}

int read_buf(const string& file, /* out */ unsigned char* buf, const int& len)
{
    ifstream stream;
    stream.open(file, ios::in | ios::binary);
    if (stream.is_open())
    {
        stream.read((char*)buf, len);
        stream.close();
        return stream.gcount();
    }
    return -1;
}

int write_buf(const string& file, /* in */ unsigned char* buf, const int& len)
{
	std::ofstream os(file, std::ofstream::out | std::ofstream::binary | std::ofstream::trunc);
	if (os.is_open())
	{
		os.write((char*)buf, len);
		if (!os)
		{
            os.close();
			exit(-1);
		}
		os.close();
		return len;
	}
	return -1;
}

int read_str(const string& file, /* out */ string& out)
{
    ifstream stream;
    stream.open(file, ios::out);
    if (stream.is_open())
    {
        stringstream ss;
        char c;
        while (stream.get(c))
        {
            ss << c;
        }
        out = ss.str();
        return ss.str().size();
    }
    return 0;
}

int write_str(const string& file, /* in */ string& out)
{
    ofstream stream;
    stream.open(file, ios::out);
    if (stream.is_open())
    {
        stream << out;
        stream.close();
        return out.size();
    }
    return 0;
}

void read_sstream(const string& file, /* out */ stringstream& sstrm)
{
    ifstream stream;
    stream.open(file, ios::in);
    if (stream.is_open())
    {
        string line;
        while (getline(stream, line))
        {
            sstrm << line;
        }
        stream.close();
    }
}

void write_sstream(const string& file, /* in */ stringstream& sstrm)
{
    ofstream stream;
    stream.open(file, ios::out);
    if (stream.is_open())
    {
        stream << sstrm.str();
        stream.close();
    }
}

void write_lines(const string& file, /* in */ const vector<string>& lines)
{
    std::ofstream os(file, std::ofstream::out | std::ofstream::trunc);
	if (os.is_open())
	{
        string s;
        int len = lines.size();
        for(int i = 0; i < len; ++i)
        {
            s = lines[i];
            s.append("\n");  // append new line
		    os.write(s.c_str(), s.size());
        }
	}
    os.close();
}

vector<string>& read_lines(const string& file, /* out */ vector<string>& lines)
{
    ifstream stream;
    stream.open(file, ios::out);
    if (stream.is_open())
    {
        string line;
        while (getline(stream, line))
        {
            lines.push_back(line);
        }
        stream.close();
    }
    return lines;
}
