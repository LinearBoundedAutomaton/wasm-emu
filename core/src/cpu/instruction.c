#include <stdio.h>

#include "instruction.h"
#include "opcode.h"

//The value used to mask the first byte opcode value
#define OPCODE_BYTE_ONE_MASK 0xFC

//the amount to shift the first byte of the opcode by
#define OPCODE_BYTE_ONE_SHIFT 2

void decodeInstruction(void * memory, Instruction * instruction){
    instruction->opcode = ((int8_t *)memory)[0] << OPCODE_BYTE_ONE_SHIFT & OPCODE_BYTE_ONE_MASK;
    switch(instruction->opcode){
        case OPCODE_ADD:
            instruction->size = 3;
            break;
        case OPCODE_HLT:
            instruction->size = 1;
            break;
    }
}