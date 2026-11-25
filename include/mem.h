#ifndef MEM_H_
#define MEM_H_

#include <stdint.h>

typedef struct Mem_Usage
{
    unsigned int used;
    unsigned int available;
    unsigned int cached;
    unsigned int free;
} Mem_Usage;

int get_mem_capacity(uint64_t *mem_size_kib);

int get_mem_usage(Mem_Usage *mem_usage);

#endif // MEM_H_