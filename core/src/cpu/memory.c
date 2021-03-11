#include <stdio.h>
#include <stdlib.h>
#include "memory.h"


void initMemory(int8_t * memory){
    memory = (int8_t *)malloc(MEMORY_SIZE);
    if(memory == NULL){
        printf("Failed to allocate main memory segment\n");
        fflush(stdout);
        exit(1);
    }
}