#include "cpu.h"
#include "mem.h"
#include "proc.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

int main()
{
    char cpu_name[128];

    Mem_Usage mem_usage = {
        0,
        0,
        0,
        0,
    };

    uint64_t mem_size_kib = 0;

    size_t proc_count = 0;

    int res;

    res = get_cpu_info(cpu_name, sizeof(cpu_name));
    if (res != 0)
    {
        perror("Couldnt retrieve cpu info\n");
        return EXIT_FAILURE;
    }

    res = get_mem_capacity(&mem_size_kib);
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

    res = get_mem_usage(&mem_usage);
    if (res != 0)
    {
        perror("Couldnt retrieve memory usage\n");
        return EXIT_FAILURE;
    }

    printf("CPU: %s", cpu_name);

    printf("RAM capacity: %luGB\n", mem_size_kib >> 20);

    printf("Processes: %zu\n", proc_count);

    printf("RAM used: %u%%\n", mem_usage.used);

    printf("RAM available: %u%%\n", mem_usage.available);

    printf("RAM cached: %u%%\n", mem_usage.cached);

    printf("RAM free: %u%%\n", mem_usage.free);

    return EXIT_SUCCESS;
}