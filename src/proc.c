#include "proc.h"

#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include "utils.h"

int get_proc_count(size_t *proc_count)
{
    // reset process count
    *proc_count = 0;

    DIR *dir = opendir("/proc");

    struct dirent *entry;

    while ((entry = readdir(dir)) != NULL)
    {
        // check if proc entry is a pid
        if (isint(entry->d_name))
        {
            (*proc_count)++;
        }
    };

    // release directory stream
    closedir(dir);
    dir = NULL;

    return 0;
}