// This file is part of echo2.

// echo2 is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// echo2 is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with echo2.  If not, see <https://www.gnu.org/licenses/>.

#include <iostream>
#include <cstring>
#include <string>
#include <unistd.h>         /* for STDIN_FILENO */
#include <sys/select.h>     /* for pselect   */
#include "main.hpp"

using std::cin;
using std::string;

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
		if(stdin_ready (STDIN_FILENO))
		{
				string buffer;
				cin >> buffer;
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
