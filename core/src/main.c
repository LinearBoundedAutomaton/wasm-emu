#include<stdio.h>
#include "./cpu/cpu.h"
#include "./cpu/memory.h"


int main(int argc, char **argv){
    printf("Creating memory segment\n");
    int8_t * memory;
    initMemory(memory);
    printf("\"Powering up\" processor!\n");
    initCPU(memory);
    printf("Initialized processor!\n");
    int i = 0;
    for(i = 0; i < 10; i++){
        printf("Executing instruction %d\n",i);
        execCycle();
    }
    printf("Shuting down processor\n");
    fflush(stdout);
    return 0;
}