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
        char allfiles[10][100];
        while ((dir = readdir(d)) != NULL)
        {
            // strcpy is imported from string.h which copies the string to array from given char
            strcpy(allfiles[index++], dir->d_name);
            // printf("%s\n", dir->d_name);
        }
        closedir(d);

        for (size_t i = 0; i < 6; i++)
        {
            if (strcmp(allfiles[i], "export_so.c") != 0)
            {
                printf("%s\n", allfiles[i]);
            }
        }
    }

    return (0);
}