#include <iostream>
#include <cstring>
#include <string>
#include <unistd.h>         /* for STDIN_FILENO */
#include <sys/select.h>     /* for pselect   */
#include "main.hpp"
#include <vector>

using namespace std;

int stdin_ready (int filedes)
{
    fd_set set;
    /* declare/initialize zero timeout */
    struct timespec timeout = { .tv_sec = 0 };
    /* Initialize the file descriptor set. */
    FD_ZERO (&set);
    FD_SET (filedes, &set);
    /* check whestdin_ready is ready on filedes */
    return pselect (filedes + 1, &set, NULL, NULL, &timeout, NULL);
}

int main(int argc, char* argv[])
{
	try
	{
		vector<string> args;
		args.assign(argv, argv + argc);

		if(stdin_ready (STDIN_FILENO))
		{
				string buffer;
				cin >> buffer;
				args.push_back(buffer);
		}
		return parse_options(args);
	}
	catch(std::logic_error& ex)
	{
	 	std::cout << ex.what() << std::endl;
	}
}

