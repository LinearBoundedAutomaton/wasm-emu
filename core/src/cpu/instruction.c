#include <stdio.h>

#include "instruction.h"
#include "registers.h"

//The value used to mask the first byte opcode value
#define OPCODE_BYTE_ONE_MASK 0xFC

//the amount to shift the first byte of the opcode by
#define OPCODE_BYTE_ONE_SHIFT 2

#define INSTRUCTION_BYTEDNESS 2

void fetchAndDecodeInstruction(void * memory, RegisterHolder * registers, Instruction * instruction){
    instruction->opcode = ((int8_t *)memory)[0] << OPCODE_BYTE_ONE_SHIFT & OPCODE_BYTE_ONE_MASK;

    // A wonderful reference for making sense of this gibberish:
    // http://ref.x86asm.net/coder32.html
    switch(instruction->opcode){
        //How these are listed is
        // [OPCODE] [MNEMONIC]


        int8_t width;

        //
        // SUCCESSIVE ADD BLOCKS
        //
        // 0x00     MOD_R_8 - R_8
        case 0x00:
            instruction->type = ADD;
            width = 1;
            instruction->op1 = decodeRegisterModRM(registers, ((int8_t *)memory) + 1,  width,  REGISTER_DECODE_MOD);
            instruction->op2 = decodeRegisterModRM(registers, ((int8_t *)memory) + 2,  width,  REGISTER_NO_DECODE_MOD);
            instruction->size = 3;
            break;
        // 0x01     MOD_R_32 - R_32
        case 0x01:
            instruction->type = ADD;
            width = INSTRUCTION_BYTEDNESS;
            instruction->op1 = decodeRegisterModRM(registers, ((int8_t *)memory) + 1,  width,  REGISTER_DECODE_MOD);
            instruction->op2 = decodeRegisterModRM(registers, ((int8_t *)memory) + 2,  width,  REGISTER_NO_DECODE_MOD);
            instruction->size = 3;
            break;
        // 0x02      R_8 - MOD_R_8
        case 0x02:
            instruction->type = ADD;
            width = 1;
            instruction->op1 = decodeRegisterModRM(registers, ((int8_t *)memory) + 1,  width,  REGISTER_NO_DECODE_MOD);
            instruction->op2 = decodeRegisterModRM(registers, ((int8_t *)memory) + 2,  width,  REGISTER_DECODE_MOD);
            instruction->size = 3;
            break;
        // 0x03      R_32 - MOD_R_32
        case 0x03:
            instruction->type = ADD;
            width = INSTRUCTION_BYTEDNESS;
            instruction->op1 = decodeRegisterModRM(registers, ((int8_t *)memory) + 1,  width,  REGISTER_NO_DECODE_MOD);
            instruction->op2 = decodeRegisterModRM(registers, ((int8_t *)memory) + 2,  width,  REGISTER_DECODE_MOD);
            instruction->size = 3;
            break;
        // 0x04      AL - IMM_8
        case 0x04:
            instruction->type = ADD;
            width = 1;
            instruction->op1 = registers->AL;
            instruction->op2 = ((int8_t *)memory) + 1;
            instruction->size = 2;
            break;
        // 0x05      EAX - IMM_32
        case 0x05:
            instruction->type = ADD;
            width = INSTRUCTION_BYTEDNESS;
            instruction->op1 = registers->EAX;
            instruction->op2 = ((int8_t *)memory) + 1;
            instruction->size = 5;
            break;





        // 0x06 PUSH
        case 0x06:
            instruction->type = PUSH;
            width = 2;
            instruction->op1 = registers->ES;
            instruction->size = 1;
            break;



        // 0x07 POP
        case 0x07:
            instruction->type = POP;
            width = 2;
            instruction->op1 = registers->ES;
            instruction->size = 1;
            break;





        //
        // SUCCESSIVE OR BLOCKS
        //
        // 0x08     MOD_R_8 - R_8
        case 0x08:
            instruction->type = OR;
            width = 1;
            instruction->op1 = decodeRegisterModRM(registers, ((int8_t *)memory) + 1,  width,  REGISTER_DECODE_MOD);
            instruction->op2 = decodeRegisterModRM(registers, ((int8_t *)memory) + 2,  width,  REGISTER_NO_DECODE_MOD);
            instruction->size = 3;
            break;
        // 0x09     MOD_R_32 - R_32
        case 0x09:
            instruction->type = OR;
            width = INSTRUCTION_BYTEDNESS;
            instruction->op1 = decodeRegisterModRM(registers, ((int8_t *)memory) + 1,  width,  REGISTER_DECODE_MOD);
            instruction->op2 = decodeRegisterModRM(registers, ((int8_t *)memory) + 2,  width,  REGISTER_NO_DECODE_MOD);
            instruction->size = 3;
            break;
        // 0x0A      R_8 - MOD_R_8
        case 0x0A:
            instruction->type = OR;
            width = 1;
            instruction->op1 = decodeRegisterModRM(registers, ((int8_t *)memory) + 1,  width,  REGISTER_NO_DECODE_MOD);
            instruction->op2 = decodeRegisterModRM(registers, ((int8_t *)memory) + 2,  width,  REGISTER_DECODE_MOD);
            instruction->size = 3;
            break;
        // 0x0B      R_32 - MOD_R_32
        case 0x0B:
            instruction->type = OR;
            width = INSTRUCTION_BYTEDNESS;
            instruction->op1 = decodeRegisterModRM(registers, ((int8_t *)memory) + 1,  width,  REGISTER_NO_DECODE_MOD);
            instruction->op2 = decodeRegisterModRM(registers, ((int8_t *)memory) + 2,  width,  REGISTER_DECODE_MOD);
            instruction->size = 3;
            break;
        // 0x0C      AL - IMM_8
        case 0x0C:
            instruction->type = OR;
            width = 1;
            instruction->op1 = registers->AL;
            instruction->op2 = ((int8_t *)memory) + 1;
            instruction->size = 2;
            break;
        // 0x0D      EAX - IMM_32
        case 0x0D:
            instruction->type = OR;
            width = INSTRUCTION_BYTEDNESS;
            instruction->op1 = registers->EAX;
            instruction->op2 = ((int8_t *)memory) + 1;
            instruction->size = 5;
            break;





        // 0x0E PUSH
        case 0x0E:
            instruction->type = PUSH;
            width = 2;
            instruction->op1 = registers->CS;
            instruction->size = 1;
            break;




        //
        // SUCCESSIVE ADC BLOCKS
        //
        // 0x10     MOD_R_8 - R_8
        case 0x10:
            instruction->type = ADC;
            width = 1;
            instruction->op1 = decodeRegisterModRM(registers, ((int8_t *)memory) + 1,  width,  REGISTER_DECODE_MOD);
            instruction->op2 = decodeRegisterModRM(registers, ((int8_t *)memory) + 2,  width,  REGISTER_NO_DECODE_MOD);
            instruction->size = 3;
            break;
        // 0x11     MOD_R_32 - R_32
        case 0x11:
            instruction->type = ADC;
            width = INSTRUCTION_BYTEDNESS;
            instruction->op1 = decodeRegisterModRM(registers, ((int8_t *)memory) + 1,  width,  REGISTER_DECODE_MOD);
            instruction->op2 = decodeRegisterModRM(registers, ((int8_t *)memory) + 2,  width,  REGISTER_NO_DECODE_MOD);
            instruction->size = 3;
            break;
        // 0x12      R_8 - MOD_R_8
        case 0x12:
            instruction->type = ADC;
            width = 1;
            instruction->op1 = decodeRegisterModRM(registers, ((int8_t *)memory) + 1,  width,  REGISTER_NO_DECODE_MOD);
            instruction->op2 = decodeRegisterModRM(registers, ((int8_t *)memory) + 2,  width,  REGISTER_DECODE_MOD);
            instruction->size = 3;
            break;
        // 0x13      R_32 - MOD_R_32
        case 0x13:
            instruction->type = ADC;
            width = INSTRUCTION_BYTEDNESS;
            instruction->op1 = decodeRegisterModRM(registers, ((int8_t *)memory) + 1,  width,  REGISTER_NO_DECODE_MOD);
            instruction->op2 = decodeRegisterModRM(registers, ((int8_t *)memory) + 2,  width,  REGISTER_DECODE_MOD);
            instruction->size = 3;
            break;
        // 0x14      AL - IMM_8
        case 0x14:
            instruction->type = ADC;
            width = 1;
            instruction->op1 = registers->AL;
            instruction->op2 = ((int8_t *)memory) + 1;
            instruction->size = 2;
            break;
        // 0x15      EAX - IMM_32
        case 0x15:
            instruction->type = ADC;
            width = INSTRUCTION_BYTEDNESS;
            instruction->op1 = registers->EAX;
            instruction->op2 = ((int8_t *)memory) + 1;
            instruction->size = 5;
            break;







        // 0x16 PUSH
        case 0x16:
            instruction->type = PUSH;
            width = 2;
            instruction->op1 = registers->SS;
            instruction->size = 2;
            break;

        // 0x17 POP
        case 0x17:
            instruction->type = POP;
            width = 2;
            instruction->op1 = registers->SS;
            instruction->size = 1;
            break;





        //
        // SUCCESSIVE SBB BLOCKS
        //
        // 0x18     MOD_R_8 - R_8
        case 0x18:
            instruction->type = SBB;
            width = 1;
            instruction->op1 = decodeRegisterModRM(registers, ((int8_t *)memory) + 1,  width,  REGISTER_DECODE_MOD);
            instruction->op2 = decodeRegisterModRM(registers, ((int8_t *)memory) + 2,  width,  REGISTER_NO_DECODE_MOD);
            instruction->size = 3;
            break;
        // 0x19     MOD_R_32 - R_32
        case 0x19:
            instruction->type = SBB;
            width = INSTRUCTION_BYTEDNESS;
            instruction->op1 = decodeRegisterModRM(registers, ((int8_t *)memory) + 1,  width,  REGISTER_DECODE_MOD);
            instruction->op2 = decodeRegisterModRM(registers, ((int8_t *)memory) + 2,  width,  REGISTER_NO_DECODE_MOD);
            instruction->size = 3;
            break;
        // 0x1A      R_8 - MOD_R_8
        case 0x1A:
            instruction->type = SBB;
            width = 1;
            instruction->op1 = decodeRegisterModRM(registers, ((int8_t *)memory) + 1,  width,  REGISTER_NO_DECODE_MOD);
            instruction->op2 = decodeRegisterModRM(registers, ((int8_t *)memory) + 2,  width,  REGISTER_DECODE_MOD);
            instruction->size = 3;
            break;
        // 0x1B      R_32 - MOD_R_32
        case 0x1B:
            instruction->type = SBB;
            width = INSTRUCTION_BYTEDNESS;
            instruction->op1 = decodeRegisterModRM(registers, ((int8_t *)memory) + 1,  width,  REGISTER_NO_DECODE_MOD);
            instruction->op2 = decodeRegisterModRM(registers, ((int8_t *)memory) + 2,  width,  REGISTER_DECODE_MOD);
            instruction->size = 3;
            break;
        // 0x1C      AL - IMM_8
        case 0x1C:
            instruction->type = SBB;
            width = 1;
            instruction->op1 = registers->AL;
            instruction->op2 = ((int8_t *)memory) + 1;
            instruction->size = 2;
            break;
        // 0x1D      EAX - IMM_32
        case 0x1D:
            instruction->type = SBB;
            width = INSTRUCTION_BYTEDNESS;
            instruction->op1 = registers->EAX;
            instruction->op2 = ((int8_t *)memory) + 1;
            instruction->size = 5;
            break;





        // 0x1E PUSH
        case 0x1E:
            instruction->type = PUSH;
            width = 2;
            instruction->op1 = registers->DS;
            instruction->size = 1;
            break;

        // 0x1F POP
        case 0x1F:
            instruction->type = POP;
            width = 2;
            instruction->op1 = registers->DS;
            instruction->size = 1;
            break;




        //SUCCESSIVE AND BLOCKS
        // 0x20     MOD_R_8 - R_8
        case 0x20:
            instruction->type = AND;
            width = 1;
            instruction->op1 = decodeRegisterModRM(registers, ((int8_t *)memory) + 1,  width,  REGISTER_DECODE_MOD);
            instruction->op2 = decodeRegisterModRM(registers, ((int8_t *)memory) + 2,  width,  REGISTER_NO_DECODE_MOD);
            instruction->size = 3;
            break;
        // 0x21     MOD_R_32 - R_32
        case 0x21:
            instruction->type = AND;
            width = INSTRUCTION_BYTEDNESS;
            instruction->op1 = decodeRegisterModRM(registers, ((int8_t *)memory) + 1,  width,  REGISTER_DECODE_MOD);
            instruction->op2 = decodeRegisterModRM(registers, ((int8_t *)memory) + 2,  width,  REGISTER_NO_DECODE_MOD);
            instruction->size = 3;
            break;
        // 0x22      R_8 - MOD_R_8
        case 0x22:
            instruction->type = AND;
            width = 1;
            instruction->op1 = decodeRegisterModRM(registers, ((int8_t *)memory) + 1,  width,  REGISTER_NO_DECODE_MOD);
            instruction->op2 = decodeRegisterModRM(registers, ((int8_t *)memory) + 2,  width,  REGISTER_DECODE_MOD);
            instruction->size = 3;
            break;
        // 0x23      R_32 - MOD_R_32
        case 0x23:
            instruction->type = AND;
            width = INSTRUCTION_BYTEDNESS;
            instruction->op1 = decodeRegisterModRM(registers, ((int8_t *)memory) + 1,  width,  REGISTER_NO_DECODE_MOD);
            instruction->op2 = decodeRegisterModRM(registers, ((int8_t *)memory) + 2,  width,  REGISTER_DECODE_MOD);
            instruction->size = 3;
            break;
        // 0x24      AL - IMM_8
        case 0x24:
            instruction->type = AND;
            width = 1;
            instruction->op1 = registers->AL;
            instruction->op2 = ((int8_t *)memory) + 1;
            instruction->size = 2;
            break;
        // 0x25      EAX - IMM_32
        case 0x25:
            instruction->type = AND;
            width = INSTRUCTION_BYTEDNESS;
            instruction->op1 = registers->EAX;
            instruction->op2 = ((int8_t *)memory) + 1;
            instruction->size = 5;
            break;


        // 0x27 DAA
        case 0x27:
            instruction->type = DAA;
            width = 2;
            instruction->op1 = registers->AL;
            instruction->size = 2;
            break;



        //
        // SUCCESSIVE SUB BLOCKS
        //
        // 0x28     MOD_R_8 - R_8
        case 0x28:
            instruction->type = SUB;
            width = 1;
            instruction->op1 = decodeRegisterModRM(registers, ((int8_t *)memory) + 1,  width,  REGISTER_DECODE_MOD);
            instruction->op2 = decodeRegisterModRM(registers, ((int8_t *)memory) + 2,  width,  REGISTER_NO_DECODE_MOD);
            instruction->size = 3;
            break;
        // 0x29     MOD_R_32 - R_32
        case 0x29:
            instruction->type = SUB;
            width = INSTRUCTION_BYTEDNESS;
            instruction->op1 = decodeRegisterModRM(registers, ((int8_t *)memory) + 1,  width,  REGISTER_DECODE_MOD);
            instruction->op2 = decodeRegisterModRM(registers, ((int8_t *)memory) + 2,  width,  REGISTER_NO_DECODE_MOD);
            instruction->size = 3;
            break;
        // 0x2A      R_8 - MOD_R_8
        case 0x2A:
            instruction->type = SUB;
            width = 1;
            instruction->op1 = decodeRegisterModRM(registers, ((int8_t *)memory) + 1,  width,  REGISTER_NO_DECODE_MOD);
            instruction->op2 = decodeRegisterModRM(registers, ((int8_t *)memory) + 2,  width,  REGISTER_DECODE_MOD);
            instruction->size = 3;
            break;
        // 0x2B      R_32 - MOD_R_32
        case 0x2B:
            instruction->type = SUB;
            width = INSTRUCTION_BYTEDNESS;
            instruction->op1 = decodeRegisterModRM(registers, ((int8_t *)memory) + 1,  width,  REGISTER_NO_DECODE_MOD);
            instruction->op2 = decodeRegisterModRM(registers, ((int8_t *)memory) + 2,  width,  REGISTER_DECODE_MOD);
            instruction->size = 3;
            break;
        // 0x2C      AL - IMM_8
        case 0x2C:
            instruction->type = SUB;
            width = 1;
            instruction->op1 = registers->AL;
            instruction->op2 = ((int8_t *)memory) + 1;
            instruction->size = 2;
            break;
        // 0x2D      EAX - IMM_32
        case 0x2D:
            instruction->type = SUB;
            width = INSTRUCTION_BYTEDNESS;
            instruction->op1 = registers->EAX;
            instruction->op2 = ((int8_t *)memory) + 1;
            instruction->size = 5;
            break;


        // 0x2F DAS
        case 0x2F:
            instruction->type = DAS;
            width = 2;
            instruction->op1 = registers->AL;
            instruction->size = 2;
            break;




        //
        // SUCCESSIVE XOR BLOCKS
        //
        // 0x30     MOD_R_8 - R_8
        case 0x30:
            instruction->type = XOR;
            width = 1;
            instruction->op1 = decodeRegisterModRM(registers, ((int8_t *)memory) + 1,  width,  REGISTER_DECODE_MOD);
            instruction->op2 = decodeRegisterModRM(registers, ((int8_t *)memory) + 2,  width,  REGISTER_NO_DECODE_MOD);
            instruction->size = 3;
            break;
        // 0x31     MOD_R_32 - R_32
        case 0x31:
            instruction->type = XOR;
            width = INSTRUCTION_BYTEDNESS;
            instruction->op1 = decodeRegisterModRM(registers, ((int8_t *)memory) + 1,  width,  REGISTER_DECODE_MOD);
            instruction->op2 = decodeRegisterModRM(registers, ((int8_t *)memory) + 2,  width,  REGISTER_NO_DECODE_MOD);
            instruction->size = 3;
            break;
        // 0x32      R_8 - MOD_R_8
        case 0x32:
            instruction->type = XOR;
            width = 1;
            instruction->op1 = decodeRegisterModRM(registers, ((int8_t *)memory) + 1,  width,  REGISTER_NO_DECODE_MOD);
            instruction->op2 = decodeRegisterModRM(registers, ((int8_t *)memory) + 2,  width,  REGISTER_DECODE_MOD);
            instruction->size = 3;
            break;
        // 0x33      R_32 - MOD_R_32
        case 0x33:
            instruction->type = XOR;
            width = INSTRUCTION_BYTEDNESS;
            instruction->op1 = decodeRegisterModRM(registers, ((int8_t *)memory) + 1,  width,  REGISTER_NO_DECODE_MOD);
            instruction->op2 = decodeRegisterModRM(registers, ((int8_t *)memory) + 2,  width,  REGISTER_DECODE_MOD);
            instruction->size = 3;
            break;
        // 0x34      AL - IMM_8
        case 0x34:
            instruction->type = XOR;
            width = 1;
            instruction->op1 = registers->AL;
            instruction->op2 = ((int8_t *)memory) + 1;
            instruction->size = 2;
            break;
        // 0x35      EAX - IMM_32
        case 0x35:
            instruction->type = XOR;
            width = INSTRUCTION_BYTEDNESS;
            instruction->op1 = registers->EAX;
            instruction->op2 = ((int8_t *)memory) + 1;
            instruction->size = 5;
            break;





        // 0x37 AAA
        case 0x37:
            instruction->type = AAA;
            width = 2;
            instruction->op1 = registers->AL;
            instruction->size = 2;
            break;




        //
        //SUCCESSIVE CMP BLOCKS
        //
        // 0x38     MOD_R_8 - R_8
        case 0x38:
            instruction->type = CMP;
            width = 1;
            instruction->op1 = decodeRegisterModRM(registers, ((int8_t *)memory) + 1,  width,  REGISTER_DECODE_MOD);
            instruction->op2 = decodeRegisterModRM(registers, ((int8_t *)memory) + 2,  width,  REGISTER_NO_DECODE_MOD);
            instruction->size = 3;
            break;
        // 0x39     MOD_R_32 - R_32
        case 0x39:
            instruction->type = CMP;
            width = INSTRUCTION_BYTEDNESS;
            instruction->op1 = decodeRegisterModRM(registers, ((int8_t *)memory) + 1,  width,  REGISTER_DECODE_MOD);
            instruction->op2 = decodeRegisterModRM(registers, ((int8_t *)memory) + 2,  width,  REGISTER_NO_DECODE_MOD);
            instruction->size = 3;
            break;
        // 0x3A      R_8 - MOD_R_8
        case 0x3A:
            instruction->type = CMP;
            width = 1;
            instruction->op1 = decodeRegisterModRM(registers, ((int8_t *)memory) + 1,  width,  REGISTER_NO_DECODE_MOD);
            instruction->op2 = decodeRegisterModRM(registers, ((int8_t *)memory) + 2,  width,  REGISTER_DECODE_MOD);
            instruction->size = 3;
            break;
        // 0x3B      R_32 - MOD_R_32
        case 0x3B:
            instruction->type = CMP;
            width = INSTRUCTION_BYTEDNESS;
            instruction->op1 = decodeRegisterModRM(registers, ((int8_t *)memory) + 1,  width,  REGISTER_NO_DECODE_MOD);
            instruction->op2 = decodeRegisterModRM(registers, ((int8_t *)memory) + 2,  width,  REGISTER_DECODE_MOD);
            instruction->size = 3;
            break;
        // 0x3C      AL - IMM_8
        case 0x3C:
            instruction->type = CMP;
            width = 1;
            instruction->op1 = registers->AL;
            instruction->op2 = ((int8_t *)memory) + 1;
            instruction->size = 2;
            break;
        // 0x3D      EAX - IMM_32
        case 0x3D:
            instruction->type = CMP;
            width = INSTRUCTION_BYTEDNESS;
            instruction->op1 = registers->EAX;
            instruction->op2 = ((int8_t *)memory) + 1;
            instruction->size = 5;
            break;





        // 0x3F AAS
        case 0x3F:
            instruction->type = AAS;
            width = 2;
            instruction->op1 = registers->AL;
            instruction->size = 2;
            break;




        // 0x40+r INC
        case 0x40:
            instruction->type = INC;
            width = 2;
            instruction->op1 = decodeRegisterModRM(registers, ((int8_t *)memory) + 1,  width,  REGISTER_NO_DECODE_MOD);
            instruction->size = 2;
            break;




        // 0x48+r DEC
        case 0x48:
            instruction->type = DEC;
            width = 2;
            instruction->op1 = decodeRegisterModRM(registers, ((int8_t *)memory) + 1,  width,  REGISTER_NO_DECODE_MOD);
            instruction->size = 2;
            break;


        // 0x50+r PUSH
        case 0x50:
            instruction->type = PUSH;
            width = 2;
            instruction->op1 = decodeRegisterModRM(registers, ((int8_t *)memory) + 1,  width,  REGISTER_NO_DECODE_MOD);
            instruction->size = 2;
            break;

        // 0x58+r POP
        case 0x58:
            instruction->type = POP;
            width = 2;
            instruction->op1 = decodeRegisterModRM(registers, ((int8_t *)memory) + 1,  width,  REGISTER_NO_DECODE_MOD);
            instruction->size = 2;
            break;

        // 0x60 PUSHA/D
        case 0x60:
            instruction->type = PUSHA;
            width = INSTRUCTION_BYTEDNESS;
            instruction->size = 1;
            break;

        // 0x61 POPA/D
        case 0x61:
            instruction->type = PUSHA;
            width = INSTRUCTION_BYTEDNESS;
            instruction->size = 1;
            break;
        
        // 0x62 BOUND
        case 0x62:
            instruction->type = BOUND;
            width = INSTRUCTION_BYTEDNESS;
            instruction->op1 = decodeRegisterModRM(registers, ((int8_t *)memory) + 1,  width,  REGISTER_NO_DECODE_MOD);
            instruction->op2 = ((int8_t *)memory) + 2;
            instruction->op3 = registers->EFLAGS;
            instruction->size = 4;
            break;

        // 0x63 ARPL
        case 0x63:
            instruction->type = ARPL;
            width = 2;
            instruction->op1 = decodeRegisterModRM(registers, ((int8_t *)memory) + 1,  width,  REGISTER_DECODE_MOD);
            instruction->op2 = decodeRegisterModRM(registers, ((int8_t *)memory) + 2,  width,  REGISTER_NO_DECODE_MOD);
            instruction->size = 3;
            break;

        // 0x68 PUSH
        case 0x68:
            instruction->type = PUSH;
            width = INSTRUCTION_BYTEDNESS;
            instruction->op1 = ((int8_t *)memory) + 1;
            instruction->size = 1 + INSTRUCTION_BYTEDNESS;
            break;
            
        // 0x69 IMUL
        case 0x69:
            instruction->type = IMUL;
            width = INSTRUCTION_BYTEDNESS;
            instruction->op1 = decodeRegisterModRM(registers, ((int8_t *)memory) + 1,  width,  REGISTER_NO_DECODE_MOD);
            instruction->op2 = decodeRegisterModRM(registers, ((int8_t *)memory) + 2,  width,  REGISTER_DECODE_MOD);
            instruction->op3 = ((int8_t *)memory) + 3;
            instruction->size = 3 + INSTRUCTION_BYTEDNESS;
            break;

        // 0x6A PUSH
        case 0x6A:
            instruction->type = PUSH;
            width = 2;
            instruction->op1 = ((int8_t *)memory) + 1;
            instruction->size = 2;
            break;

        // 0x6B IMUL
        case 0x6B:
            instruction->type = IMUL;
            width = INSTRUCTION_BYTEDNESS;
            instruction->op1 = decodeRegisterModRM(registers, ((int8_t *)memory) + 1,  width,  REGISTER_NO_DECODE_MOD);
            instruction->op2 = decodeRegisterModRM(registers, ((int8_t *)memory) + 2,  width,  REGISTER_DECODE_MOD);
            instruction->op3 = ((int8_t *)memory) + 3;
            instruction->size = 4;
            break;

        // 0x6C INSB
        case 0x6C:
            instruction->type = INS;
            width = 1;
            instruction->op1 = ((int8_t *)memory) + 1;
            instruction->op2 = registers->DX;
            instruction->size = 2;

        // 0x6D INSD
        case 0x6D:
            instruction->type = INS;
            width = INSTRUCTION_BYTEDNESS;
            instruction->op1 = ((int8_t *)memory) + 1;
            instruction->op2 = registers->DX;
            instruction->size = 1 + INSTRUCTION_BYTEDNESS;
            break;

        // 0x6E OUTSB
        case 0x6E:
            instruction->type = OUTS;
            width = 1;
            instruction->op1 = registers->DX;
            instruction->op2 = ((int8_t *)memory) + 1;
            instruction->size = 2;
            break;

        // 0x6F OUTSD
        case 0x6F:
            instruction->type = OUTS;
            width = INSTRUCTION_BYTEDNESS;
            instruction->op1 = registers->DX;
            instruction->op2 = ((int8_t *)memory) + 1;
            instruction->size = 1 + INSTRUCTION_BYTEDNESS;
            break;

        // 0x70 JO
        case 0x70:
            instruction->type = JO;
            width = 2;
            instruction->op1 = ((int8_t *)memory) + 1;
            instruction->size = 2;
            break;

        // 0x71 JNO
        case 0x71:
            instruction->type = JNO;
            width = 2;
            instruction->op1 = ((int8_t *)memory) + 1;
            instruction->size = 2;
            break;

        // 0x72 JB/JNAE/JC
        case 0x72:
            instruction->type = JB;
            width = 2;
            instruction->op1 = ((int8_t *)memory) + 1;
            instruction->size = 2;
            break;

        // 0x73 JNB/JAE/JNC
        case 0x73:
            instruction->type = JNB;
            width = 2;
            instruction->op1 = ((int8_t *)memory) + 1;
            instruction->size = 2;
            break;

        // 0x74x JZ/JE
        case 0x74:
            instruction->type = JZ;
            width = 2;
            instruction->op1 = ((int8_t *)memory) + 1;
            instruction->size = 2;
            break;

        // 0x75 JNZ/JNE
        case 0x75:
            instruction->type = JNZ;
            width = 2;
            instruction->op1 = ((int8_t *)memory) + 1;
            instruction->size = 2;
            break;

        // 0x76 JBE/JNA
        case 0x76:
            instruction->type = JBE;
            width = 2;
            instruction->op1 = ((int8_t *)memory) + 1;
            instruction->size = 2;
            break;

        // 0x77 JNBE/JA
        case 0x77:
            instruction->type = JNBE;
            width = 2;
            instruction->op1 = ((int8_t *)memory) + 1;
            instruction->size = 2;
            break;

        // 0x78 JS
        case 0x78:
            instruction->type = JS;
            width = 2;
            instruction->op1 = ((int8_t *)memory) + 1;
            instruction->size = 2;
            break;

        // 0x79 JNS
        case 0x79:
            instruction->type = JNS;
            width = 2;
            instruction->op1 = ((int8_t *)memory) + 1;
            instruction->size = 2;
            break;

        // 0x7A JP/JPE
        case 0x7A:
            instruction->type = JP;
            width = 2;
            instruction->op1 = ((int8_t *)memory) + 1;
            instruction->size = 2;
            break;

        // 0x7B JNP/JPO
        case 0x7B:
            instruction->type = JNP;
            width = 2;
            instruction->op1 = ((int8_t *)memory) + 1;
            instruction->size = 2;
            break;

        // 0x7C JL/JNGE
        case 0x7C:
            instruction->type = JL;
            width = 2;
            instruction->op1 = ((int8_t *)memory) + 1;
            instruction->size = 2;
            break;

        // 0x7D JNL/JGE
        case 0x7D:
            instruction->type = JNL;
            width = 2;
            instruction->op1 = ((int8_t *)memory) + 1;
            instruction->size = 2;
            break;

        // 0x7E JLE/JNG
        case 0x7E:
            instruction->type = JLE; 
            width = 2;
            instruction->op1 = ((int8_t *)memory) + 1;
            instruction->size = 2;
            break;

        // 0x7F JNLE/JG
        case 0x7F:
            instruction->type = JNLE;
            width = 2;
            instruction->op1 = ((int8_t *)memory) + 1;
            instruction->size = 2;
            break;


        // 0x80   LOTS OF EXTENSIONS POSSIBLE
        case 0x80:
            width = 1;
            instruction->op1 = decodeRegisterModRM(registers, ((int8_t *)memory) + 1,  width,  REGISTER_DECODE_MOD);
            instruction->op2 = ((int8_t *)memory) + 2;
            instruction->size = 3;
            break;

        // 0x81   LOTS OF EXTENSIONS POSSIBLE
        case 0x81:
            width = INSTRUCTION_BYTEDNESS;
            instruction->op1 = decodeRegisterModRM(registers, ((int8_t *)memory) + 1,  width,  REGISTER_DECODE_MOD);
            instruction->op2 = ((int8_t *)memory) + 2;
            instruction->size = 1 + 2 * INSTRUCTION_BYTEDNESS;
            break;

        // 0x82   LOTS OF EXTENSIONS POSSIBLE
        case 0x82:
            width = 1;
            instruction->op1 = decodeRegisterModRM(registers, ((int8_t *)memory) + 1,  width,  REGISTER_DECODE_MOD);
            instruction->op2 = ((int8_t *)memory) + 2;
            instruction->size = 3;
            break;

        // 0x83   LOTS OF EXTENSIONS POSSIBLE
        case 0x83:
            width = INSTRUCTION_BYTEDNESS;
            instruction->op1 = decodeRegisterModRM(registers, ((int8_t *)memory) + 1,  width,  REGISTER_DECODE_MOD);
            instruction->op2 = ((int8_t *)memory) + 2;
            instruction->size = 1 + 2 * INSTRUCTION_BYTEDNESS;
            break;



        // 0x84 TEST
        case 0x84:
            instruction->type = TEST;
            width = 1;
            instruction->op1 = decodeRegisterModRM(registers, ((int8_t *)memory) + 1,  width,  REGISTER_DECODE_MOD);
            instruction->op2 = decodeRegisterModRM(registers, ((int8_t *)memory) + 1,  width,  REGISTER_NO_DECODE_MOD);
            instruction->size = 3;
            break;





    }
    
}


