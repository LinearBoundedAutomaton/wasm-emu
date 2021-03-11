#include <stdio.h>
#include <stdlib.h>

#include "cpu.h"
#include "memory.h"
#include "instruction.h"
#include "registers.h"


//used to mask byte to find MOD value of register
#define REGISTER_MOD_MASK 0x03
#define REGISTER_MOD_SHIFT 6

//used to mask byte to find Reg value of register
#define REGISTER_REG_MASK 0x07
#define REGISTER_REG_SHIFT 3

//used to mask byte to find R/M value of register
#define REGISTER_RM_MASK 0x03
#define REGISTER_RM_SHIFT 0



//The block of memory the CPU pulls instructions from
void * memory;
//The current instruction the CPU is executing
Instruction * currentInstruction;
//The registers container
RegisterHolder * registers;


//initialized the CPU
void initCPU(void * targetMemory){
    currentInstruction = (Instruction *)malloc(sizeof(Instruction));
    initializeRegisterHolder(registers);
    memory = targetMemory;
    registers->IP = (int8_t *)memory;
}


void execInstruction(Instruction * instr){
    
}



void cpuRunLimited(int cycleCount){
    int currentCycle = 0;
    for(currentCycle = 0; currentCycle < cycleCount; currentCycle++){
        fetchAndDecodeInstruction(registers->IP, registers, currentInstruction);
        execInstruction(currentInstruction);
        registers->IP = registers->IP + currentInstruction->size;
    }
}



void cpuRun(){
    fetchAndDecodeInstruction(registers->IP, registers, currentInstruction);
    execInstruction(currentInstruction);
    registers->IP = registers->IP + currentInstruction->size;
}