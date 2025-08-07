#ifndef UTIL_FUNCTIONS_H
#define UTIL_FUNCTIONS_H

#include <stdint.h>
#include <stdio.h>

/* Memory-mapped registers */
#define MR_KBSR 0xFE00 /* keyboard status */
#define MR_KBDR 0xFE02 /* keyboard data */

/* Function declarations */
extern uint16_t* memory;  // Reference to memory array defined in lc3-vm

uint16_t sign_extend(uint16_t x, int bit_count);
void handle_interrupt(int signal);
uint16_t swap16(uint16_t x);
void update_flags(uint16_t r);
void read_image_file(FILE *file);
int read_image(const char *image_path);
uint16_t check_key(void);
void mem_write(uint16_t address, uint16_t val);
uint16_t mem_read(uint16_t address);

void disable_input_buffering(void);
void restore_input_buffering(void);

#endif /* UTIL_FUNCTIONS_H */