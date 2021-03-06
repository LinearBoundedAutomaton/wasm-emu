#ifndef REGISTER_H
#define REGISTER_H
#include <stdint.h>


//General Registers
int8_t * REGISTER_AX;
int8_t * REGISTER_BX;
int8_t * REGISTER_CX;
int8_t * REGISTER_DX;

//Index registers
int8_t * REGISTER_SI;
int8_t * REGISTER_DI;
int8_t * REGISTER_BP;
int8_t * REGISTER_SP;

//Program counter
int8_t * REGISTER_IP;

//Segment registers
int8_t * REGISTER_CS;
int8_t * REGISTER_DS;
int8_t * REGISTER_ES;
int8_t * REGISTER_SS;

//Status registers
int8_t * REGISTER_FLAGS;

#endif