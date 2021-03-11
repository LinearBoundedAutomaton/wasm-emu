#ifndef CPU_H
#define CPU_H

#include "instruction.h"


//initializes the CPU
void initCPU(void * targetMemory);

//executes a single instruction cycle on the cpu
void execCycle();

void execInstruction(Instruction * instr);

#endif