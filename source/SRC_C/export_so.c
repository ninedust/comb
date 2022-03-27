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
            strcpy(allfiles[index++], dir->d_name);
        }
        closedir(d);

        for (size_t i = 0; i < 6; i++)
        {
            if (allfiles[i])
            {
                char eachfiles[100];
                strcpy(eachfiles, allfiles[i]);

                if (strcmp(eachfiles, __FILE__) != 0 &&
                    eachfiles[strlen(eachfiles) - 1] == 'c' &&
                    eachfiles[strlen(eachfiles) - 2] == '.')
                {
                    char cmd[150];
                    char eachfilewithoutext[100];
                    strcpy(eachfilewithoutext, eachfiles);
                    eachfilewithoutext[strlen(eachfilewithoutext) - 1] = '\0';
                    eachfilewithoutext[strlen(eachfilewithoutext) - 1] = '\0';
                    strcpy(cmd, "gcc -shared -o ../global/");
                    strcat(cmd, eachfilewithoutext);
                    strcat(cmd, ".so -fPIC ");
                    strcat(cmd, eachfiles);

                    system(cmd);
                }
            }
        }
    }

    return (0);
}