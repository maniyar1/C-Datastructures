#include "Memory.h"
#include "stdio.h"

int main() {
    int size;
    unsigned int iterations = 0;
    void* blocc;
    ds_initialize();
    blocc = ds_makeMemoryBlock();
    while (1) {
        void* memory;
        int* mem;

        size = 1 * 1024 * 1024; /* 1MB */
        memory = ds_malloc(&blocc, size);
        printf("Still running... %i \n", iterations);
        mem = memory;
        mem[0] = 0; /* Need to use memory or you won't get a segfault, idk why no stack overflow either? */
        ds_free(&blocc, memory, size);
        iterations++;
    }
}
