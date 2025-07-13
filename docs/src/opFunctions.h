
#include <cstdint>
#ifndef OPFUNCTIONS_H
#define OPFUNCTIONS_H

// all the functions to be used for the opcodes

/*The ADD instruction takes two numbers, adds them together, and stores the result in a register*/
void ADD(uint16_t *reg, uint16_t instr);

/**/
void LDI();
/**/
void AND();
/**/
void NOT();
/**/
void BR();
/**/
void JMP();
/**/
void LD();
/**/
void STR();

#endif
