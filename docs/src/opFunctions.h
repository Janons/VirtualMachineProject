
#ifndef OPFUNCTIONS_H
#define OPFUNCTIONS_H

#include <stdio.h>
#include <stdint.h>
#include "enums.h"

// all the functions to be used for the opcodes

/*The ADD instruction takes two numbers, adds them together, and stores the result in a register*/
uint16_t ADD(uint16_t *reg, uint16_t instr, uint16_t imm5);

/**/
void LDI();
/*Bitwise And*/
uint16_t AND(uint16_t *reg, uint16_t instr, uint16_t imm5);
/*Bitwise Not*/
uint16_t NOT(uint16_t *reg, uint16_t instr);
/*Load*/
uint16_t LD(uint16_t *reg, uint16_t instr, uint16_t imm8);
/*Branch*/
void BR(uint16_t *reg, uint16_t instr, uint16_t imm8);
/*Jump*/
void JMP(uint16_t *reg, uint16_t instr);
/**/
void JSR_R(uint16_t *reg, uint16_t instr, uint16_t imm10);
/**/
void STR();

#endif
