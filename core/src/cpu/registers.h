#ifndef REGISTER_H
#define REGISTER_H
#include <stdint.h>




#define REGISTER_DECODE_MOD 1
#define REGISTER_NO_DECODE_MOD 0


typedef struct {

    //General Registers
    int8_t * AL;
    int8_t * AH;
    int8_t * AX;
    int8_t * EAX;

    int8_t * BL;
    int8_t * BH;
    int8_t * BX;
    int8_t * EBX;

    int8_t * CL;
    int8_t * CH;
    int8_t * CX;
    int8_t * ECX;

    int8_t * DL;
    int8_t * DH;
    int8_t * DX;
    int8_t * EDX;


    //Index registers
    int8_t * ESI;
    int8_t * SI;

    int8_t * EDI;
    int8_t * DI;

    int8_t * EBP;
    int8_t * BP;

    int8_t * ESP;
    int8_t * SP;

    //Program counter
    int8_t * EIP;
    int8_t * IP;

    //Segment registers
    int8_t * CS;
    int8_t * DS;
    int8_t * ES;
    int8_t * SS;

    //Status registers
    int8_t * FLAGS;
    int8_t * EFLAGS;

} RegisterHolder;


// initializes a registers holder
void initializeRegisterHolder(RegisterHolder * registers);


// takes in a byte location and decodes it to a pointer of a register
int8_t * decodeRegisterModRM(RegisterHolder * registers, int8_t * modRMByteAddr, int8_t instructionWidth, int8_t decodeFlags);


#endif