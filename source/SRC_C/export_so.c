/*
    file made to create and export .so (shared object) files to global folder
    so that it can be used in __init__.py from where python files can import it
    from anywhere
 */

#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    DIR *d;
    struct dirent *dir;
    d = opendir(".");
    if (d)
    {
        int index = 0;
        char allfiles[100];
        while ((dir = readdir(d)) != NULL)
        {
            printf("%s\n", dir->d_name);
        }
        closedir(d);
    }
    return (0);
}