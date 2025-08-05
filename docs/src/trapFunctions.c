
#include "trapFunctions.h" // CORRECT - should use quotes for local headers
#include "enums.h"

void PUTS(uint16_t *memory, uint16_t *reg)
{
    uint16_t *c = memory + reg[R_R0];
    while (*c)
    {
        putc((char)*c, stdout);
        ++c;
    }

    fflush(stdout);
}

/*writing to the external console*/
void OUT(uint16_t *reg)
{
    uint16_t c = reg[R_R0]; // Not a pointer!
    putc((char)c, stdout);
    fflush(stdout); // Use stdout, not c
}

void PUTSP(uint16_t *memory, uint16_t *reg)
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

/*put inside the memory the characters*/
uint16_t IN(uint16_t *reg)
{
    printf("Enter a character");
    char c = getchar();

    /*for auto echoing purposes*/
    putc(c, stdout);
    fflush(stdout);

    reg[R_R0] = (uint16_t)c;
    return R_R0;
}
