
#include <stdio.h>
#include "trapFunctions.h"
#include "enums.h"

void PUTS(uint16_t memory, uint16_t *reg)
{
    uint16_t *c = memory + reg[R_R0];
    while (*c)
    {
        putc((char)*c, stdout);
        ++c;
    }

    fflush(stdout);
}