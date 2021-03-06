#include <stdio.h>
#include <stdlib.h>

#include "cpu.h"
#include "memory.h"
#include "instruction.h"
#include "opcode.h"
#include "registers.h"

//The block of memory the CPU pulls instructions from
void * memory;
//The current instruction the CPU is executing
Instruction * currentInstruction;


//initialized the CPU
void initCPU(void * targetMemory){
    currentInstruction = malloc(sizeof(Instruction));
    memory = targetMemory;
    REGISTER_IP = memory;
}

void execCycle(){
    decodeInstruction(REGISTER_IP,currentInstruction);
    switch(currentInstruction->opcode){
        case OPCODE_ADD:
            break;
        case OPCODE_HLT:
            break;
    }
    REGISTER_IP = REGISTER_IP + currentInstruction->size;
}

