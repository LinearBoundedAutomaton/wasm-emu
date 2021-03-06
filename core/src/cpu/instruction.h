#ifndef INSTRUCTION_H
#define INSTRUCTION_H
#include<stdint.h>


typedef struct {
    //instruction opcode
    int16_t opcode;
    //Register mode
    int8_t MOD;
    //Register identifier
    int8_t Reg;
    //Register/Memory operand
    int8_t RM;
    //The size of the instruction
    int8_t size;
} Instruction;

void decodeInstruction(void * memory, Instruction * instruction);


#endif