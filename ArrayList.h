#ifndef LIST
#define LIST

#include "Memory.h"
#include <string.h>

typedef char list_type;

struct {
    size_t length;
    size_t size;
    list_type* memory;
    void* blocc;
} typedef arrayList;

arrayList _makeArrayList(void* blocc, size_t length, size_t size) {
    arrayList x;

    x.length = length;
    x.size = size;
    x.memory = ds_malloc(&blocc, size);
    x.blocc = blocc;
    return x;
}

arrayList makeArrayList(void* blocc, size_t length) {
    return _makeArrayList(blocc, length, sizeof(list_type) * length);
}

void setElement(arrayList* list, size_t index, list_type element) {
    arrayList x;
    int i;

    if (index+1 > list->length) { 
        x = _makeArrayList(&list->blocc, index+1,sizeof(list_type) * index * 2);
        for (i = 0; i < list->length; i++) {
            setElement(&x, i, list->memory[i]);
        }
        setElement(&x, index, element);
        list->length  = x.length;
        list->memory = x.memory;
    } else {
        list->memory[index] = element;
    }
}

list_type getElement(arrayList* list, size_t index) {
    return list->memory[index];
}

#endif
