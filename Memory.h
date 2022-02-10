#ifndef MEMORY
#define MEMORY

#include <stddef.h>
#include <alloca.h>
#include <sys/resource.h>
#include <stdio.h>

#define block_size 32 * 1024 * 1024 /* 32MB */

unsigned int bump_pointer = 0; 
unsigned int current_size = block_size;

void ds_initialize() { /* MUST be called before everything else */ 
    _ds_initialize(block_size * 2);
}
void _ds_initialize(size_t size) {
    const rlim_t kStackSize = (size);   /* min stack size = 64 MB initially */
    struct rlimit rl;

    int result = getrlimit(RLIMIT_STACK, &rl);
    if (result == 0)
    {
        if (rl.rlim_cur < kStackSize)
        {
            rl.rlim_cur = kStackSize;
            result = setrlimit(RLIMIT_STACK, &rl);
            if (result != 0)
            {
                fprintf(stderr, "setrlimit returned result = %d\n", result);
            }
            current_size = size;
        }
    } else {
        fprintf(stderr, "getrlimit returned result = %d\n", result);
    }
}

#define ds_makeMemoryBlock() alloca(block_size)

void* ds_malloc(void** blocc, size_t size) {
    void* r = *blocc;
    *blocc = (char*) *blocc + size;
    return (void *)r;
}

void ds_free(void** blocc, void* memory, size_t size) {
    void* rewind = (char*) *blocc - size;
    if (rewind == memory) {
        *blocc = (char*) *blocc - size;
    } else {
        /* LMAO */
    }
}

#endif
