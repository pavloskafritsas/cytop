#include "cpu.h"

#include <stdio.h>
#include <string.h>

int get_cpu_info(char *buf, const size_t buf_size)
{
    const char *NEEDLE_CPU_NAME = "model name";

    char line[256];

    FILE *fp = fopen("/proc/cpuinfo", "r");

    if (!fp)
    {
        perror("Failed to open /proc/cpuinfo");

        return 1;
    }

    while (fgets(line, sizeof(line), fp))
    {
        if (strncmp(line, NEEDLE_CPU_NAME, strlen(NEEDLE_CPU_NAME)) == 0)
        {
            // Extract the value after "model name:"
            char *colon = strchr(line, ':');

            if (colon)
            {
                if (snprintf(buf, buf_size, "%s", colon + 2) < 0)
                {
                    perror("Error while retrieving cpu name.\n");

                    return -1;
                }

                break;
            }
        }
    }

    fclose(fp);

    return 0;
}