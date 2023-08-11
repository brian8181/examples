#include <sys/types.h>
#include <unistd.h>

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

void main()
{
    int fd;
    char* path = "~/tmp/test.txt";

    if ((fd = open(path, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)) == -1)
    {
        perror("Cannot open output file\n");
        exit(1);
    }

    char buf[20];
    size_t nbytes;
    ssize_t bytes_read;

    nbytes = sizeof(buf);
    bytes_read = read(fd, buf, nbytes);
}
