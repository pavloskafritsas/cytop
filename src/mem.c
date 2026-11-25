#include "mem.h"

#include <stdio.h>
#include <string.h>

int get_mem_usage(Mem_Usage *mem_usage)
{
    // TODO: retrieve the actual values

    (*mem_usage).used = 10;

    (*mem_usage).available = 20;

    (*mem_usage).cached = 30;

    (*mem_usage).free = 40;

    return 0;
}

int get_mem_capacity(uint64_t *mem_size_kib)
{
    const char *NEEDLE_MEM_TOTAL = "MemTotal";

    char line[256];

    FILE *fp = fopen("/proc/meminfo", "r");

    if (!fp)
    {
        perror("Failed to open /proc/meminfo");

        return 1;
    }

    while (fgets(line, sizeof(line), fp))
    {
        if (strncmp(line, NEEDLE_MEM_TOTAL, strlen(NEEDLE_MEM_TOTAL)) == 0)
        {
            char *colon = strchr(line, ':');

            if (colon != 0)
            {
                if (sscanf(line + strlen(NEEDLE_MEM_TOTAL) + 1, "%lu", mem_size_kib) == 1)
                {
                    break;
                }
                else
                {
                    perror("Error while retrieving mem info.\n");

                    return 1;
                }
            }
        }
    }

    fclose(fp);

    return 0;
}