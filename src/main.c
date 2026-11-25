#include "cpu.h"
#include "mem.h"
#include "proc.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <inttypes.h>

int main()
{
    char cpu_name[128];

    uint64_t mem_size_kib = 0;

    size_t proc_count = 0;

    int res;

    res = get_cpu_info(cpu_name, sizeof(cpu_name));
    if (res != 0)
    {
        perror("Couldnt retrieve cpu info\n");
        return EXIT_FAILURE;
    }

    res = get_mem_info(&mem_size_kib);
    if (res != 0)
    {
        perror("Couldnt retrieve memory info\n");
        return EXIT_FAILURE;
    }

    res = get_proc_count(&proc_count);
    if (res != 0)
    {
        perror("Couldnt retrieve process count\n");
        return EXIT_FAILURE;
    }

    printf("CPU: %s", cpu_name);

    printf("RAM: %" PRIu64 "GB\n", mem_size_kib >> 20);

    printf("Processes: %zu\n", proc_count);

    return EXIT_SUCCESS;
}