#include <stdlib.h>

#include "registers.h"


void initializeRegisterHolder(RegisterHolder * registers){
    registers = (RegisterHolder *)malloc(sizeof(RegisterHolder));
    // General register A
    registers->EAX = (int8_t *)calloc(sizeof(int8_t),4);
    registers->AX = registers->EAX + 2;
    registers->AH = registers->AX;
    registers->AL = registers->AH + 1;
    // General register B
    registers->EBX = (int8_t *)calloc(sizeof(int8_t),4);
    registers->BX = registers->EBX + 2;
    registers->BH = registers->BX;
    registers->BL = registers->BH + 1;
    // General register C
    registers->ECX = (int8_t *)calloc(sizeof(int8_t),4);
    registers->CX = registers->ECX + 2;
    registers->CH = registers->CX;
    registers->CL = registers->CH + 1;
    // General register D
    registers->EDX = (int8_t *)calloc(sizeof(int8_t),4);
    registers->DX = registers->EDX + 2;
    registers->DH = registers->DX;
    registers->DL = registers->DH + 1;
    // SI register
    registers->ESI = (int8_t *)calloc(sizeof(int8_t),4);
    registers->SI = registers->ESI + 2;
    // DI register
    registers->EDI = (int8_t *)calloc(sizeof(int8_t),4);
    registers->DI = registers->EDI + 2;
    // BP register
    registers->EBP = (int8_t *)calloc(sizeof(int8_t),4);
    registers->BP = registers->EBP + 2;
    // SP register
    registers->ESP = (int8_t *)calloc(sizeof(int8_t),4);
    registers->SP = registers->ESP + 2;
    // IP register
    registers->EIP = (int8_t *)calloc(sizeof(int8_t),4);
    registers->IP = registers->EIP + 2;
    // Segment registers
    registers->CS = (int8_t *)calloc(sizeof(int8_t),2);
    registers->DS = (int8_t *)calloc(sizeof(int8_t),2);
    registers->ES = (int8_t *)calloc(sizeof(int8_t),2);
    registers->SS = (int8_t *)calloc(sizeof(int8_t),2);
    // FLAGS register
    registers->EFLAGS = (int8_t *)calloc(sizeof(int8_t),4);
    registers->FLAGS = registers->EFLAGS + 2;
}



int8_t * decodeRegisterModRM(RegisterHolder * registers, int8_t * modRMByteAddr, int8_t instructionWidth, int8_t decodeFlags){
    
}