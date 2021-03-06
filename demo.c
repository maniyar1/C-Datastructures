#include <stdio.h>
#include "ArrayList.h"

int main (int argc, char **argv)
{
    void* blocc;
    arrayList list;

    ds_initialize();
    blocc = ds_makeMemoryBlock();

    list = makeArrayList(blocc, 4);
    setElement(&list, 0, 1);
    setElement(&list, 1, 2);
    setElement(&list, 2, 3);
    setElement(&list, 3, 4); 
    setElement(&list, 4, 5); /* Automatic resizing! */
    setElement(&list, 5, 6);
    setElement(&list, 6, 100);
    printf("Array 0: %d, Array 1: %d ... n: %d, Array n: %d \n", getElement(&list, 0), getElement(&list, 1), list.length, getElement(&list, list.length-1));
    /* Don't worry about freeing, automatically managed! */

    return 0;
}
