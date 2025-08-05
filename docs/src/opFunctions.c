#include "opFunctions.h"
#include "enums.h"

uint16_t ADD(uint16_t *reg, uint16_t instr, uint16_t imm5)
{

    /* destination register (DR) */
    uint16_t r0 = (instr >> 9) & 0x7;
    /* first operand (SR1) */
    uint16_t r1 = (instr >> 6) & 0x7;
    /* whether we are in immediate mode */
    uint16_t imm_flag = (instr >> 5) & 0x1;

    if (imm_flag)
    {

        reg[r0] = reg[r1] + imm5;
    }
    else
    {
        uint16_t r2 = instr & 0x7;
        reg[r0] = reg[r1] + reg[r2];
    }

    return r0;
}

uint16_t AND(uint16_t *reg, uint16_t instr, uint16_t imm5)
{
    /*calculation of the destination register*/
    uint16_t r0 = (instr >> 9) & 0x7;

    /*fist operand*/
    uint16_t r1 = (instr >> 6) & 0x7;

    /*checking the mode we are in*/
    uint16_t imm_flag = (instr >> 5) & 0x1;

    if (imm_flag)
    {
        // basically do the bitwise and operation
        reg[r0] = reg[r1] & imm5;
    }
    else
    {
        uint16_t r2 = instr & 0x7;
        reg[r0] = reg[r1] & reg[r2];
    }

    return r0;
}

uint16_t NOT(uint16_t *reg, uint16_t instr)
{
    uint16_t r0 = (instr >> 9) & 0x7;
    uint16_t r1 = (instr >> 6) & 0x7;

    reg[r0] = ~reg[r1];

    return r0;
}

void BR(uint16_t *reg, uint16_t instr, uint16_t imm8)
{
    uint16_t pc_offset = imm8;
    uint16_t conditional_Flag = instr >> 9 & 0x7;

    if (conditional_Flag & reg[R_COND])
    {
        reg[R_PC] += pc_offset;
    }
}

void JMP(uint16_t *reg, uint16_t instr)
{
    uint16_t base_R = instr >> 6 & 0x7;

    if (base_R == 7)
    {
        reg[R_PC] = R_R7;
    }
    else
    {
        reg[R_PC] = reg[base_R];
    }
}

void JSR_R(uint16_t *reg, uint16_t instr, uint16_t imm10)
{
    reg[R_R7] = R_PC;

    /*flag*/
    uint16_t flag = (instr >> 10) & 0x1;

    if (flag == 1)
    {
        /*base_R*/
        uint16_t base_R = (instr >> 6) & 0x7;

        reg[R_PC] = reg[base_R];
    }

    else
    {
        reg[R_PC] += imm10;
    }
}

uint16_t LD(uint16_t *reg, uint16_t instr, uint16_t imm8)
{
    // calculating DR
    uint16_t r0 = (instr >> 9) & 0x7;
}