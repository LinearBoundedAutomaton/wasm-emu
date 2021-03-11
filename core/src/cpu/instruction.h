#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include<stdint.h>

#include "registers.h"


typedef struct {
    //instruction opcode
    int16_t opcode;

    //Pointers to the operands for this instruction
    int8_t * op1;
    int8_t * op2;
    int8_t * op3;
    int8_t * op4;

    //is the instruction 1 or 2/4 bytes wide
    int8_t width;

    //The size of the instruction
    int8_t size;
} Instruction;

void fetchAndDecodeInstruction(void * memory, RegisterHolder * registers, Instruction * instruction);


#endif