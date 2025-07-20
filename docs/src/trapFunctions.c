
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

void OUT(uint16_t *reg)
{
    uint16_t *c = reg[R_R0];

    while (*c)
    {
        putc((char)*c, stdout);
        ++c;
    }

    fflush(c);
}

void PUTSP(uint16_t memory, uint16_t *reg)
{
    uint16_t *c = memory + reg[R_R0];
    while (*c)
    {
        char char1 = (*c) & 0xFF;
        putc(char1, stdout);
        char char2 = (*c) >> 8;
        if (char2)
            putc(char2, stdout);
        ++c;
    }
    fflush(stdout);
}

uint16_t IN(uint16_t *reg)
{
    printf("Enter a character");
    char c = getchar();
    putc(c, stdout);
    fflush(stdout);

    reg[R_R0] = (uint16_t)c;
    return R_R0;
}
