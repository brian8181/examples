#include <stdio.h>
#include <unistd.h>

int main(int argc, char** argv)
{
    char* path = "/home/brian/";
    //printf("%s", path);
 
    int ret = chdir(path);
    
    char buffer[256];
    getcwd(buffer, 256);

    printf("%s\n", buffer);
    return ret;
}