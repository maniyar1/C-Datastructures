#ifndef MEMORY
#define MEMORY

#include <stddef.h>
#include <alloca.h>
#include <sys/resource.h>
#include <stdio.h>

#define block_size 32 * 1024 * 1024 /* 32MB */

unsigned int bump_pointer = 0;

void ds_initialize() { /* MUST be called before everything else */
    const rlim_t kStackSize = (block_size * 2);   /* min stack size = 64 MB */
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

void ds_free(void* p) {
  /* LMAO */
}

#endif
