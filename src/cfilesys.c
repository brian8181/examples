#include <stdio.h>
#include <unistd.h>
#include <dirent.h>

int main(int argc, char** argv)
{
    char* path = "/home/brian/";
    //printf("%s", path);
    int ret = chdir(path);
    size_t bsize = 256;
    char buffer[bsize];

    getcwd(buffer, bsize);
    printf("%s\n", buffer);

    const char* dir_name = "/home/brian";
    DIR *DirectoryPointer;
    DirectoryPointer = opendir(dir_name);
    ret = closedir(DirectoryPointer);
    
    return ret;
}