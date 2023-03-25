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
    struct dirent *dir_ent;
    for(dir_ent = readdir(DirectoryPointer); dir_ent != NULL;  dir_ent = readdir(DirectoryPointer))
    {
        printf("%s\n", dir_ent->d_name);
    }
    ret = closedir(DirectoryPointer);
    
    return ret;
}