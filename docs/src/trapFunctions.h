
#include <stdint.h>

#ifndef TRAPFUNCTIONS_H
#define TRAPFUNCTIONS_H

void PUTS(uint16_t *memory, uint16_t *reg);
void OUT(uint16_t *reg);

void PUTSP(uint16_t *memory, uint16_t *reg);

uint16_t IN(uint16_t *reg);

#endif