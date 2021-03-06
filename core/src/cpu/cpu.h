#ifndef CPU_H
#define CPU_H



//initializes the CPU
void initCPU(void * targetMemory);

//executes a single instruction cycle on the cpu
void execCycle();

#endif