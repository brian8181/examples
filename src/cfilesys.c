#include <stdio.h>
#include <unistd.h>

int main(int argc, char** argv)
{
    char* path = "/home/brian/";
    //printf("%s", path);
    int ret = chdir(path);
    size_t bsize = 256;
    char buffer[bsize];

    getcwd(buffer, bsize);
    printf("%s\n", buffer);
    
    return ret;
}