#include "utils.h"
#include <stdio.h>
#include <stdlib.h>

/* Sign extends the given field to a 32-bit integer where field is
 * interpreted an n-bit integer. */ 
int sign_extend_number( unsigned int field, unsigned int n) {
    /* YOUR CODE HERE */
    return 0;
}

/* Unpacks the 32-bit machine code instruction given into the correct
 * type within the instruction struct */ 
Instruction parse_instruction(uint32_t instruction_bits) {
    /* YOUR CODE HERE */
    Instruction instruction;
    return instruction;
}

/* Return the number of bytes (from the current PC) to the branch label using the given
 * branch instruction */
int get_branch_offset(Instruction instruction) {
    /* YOUR CODE HERE */
    return 0; 
}

/* Returns the number of bytes (from the current PC) to the jump label using the given
 * jump instruction */
int get_jump_offset(Instruction instruction) {
    /* YOUR CODE HERE */
    return 0;
}

int get_store_offset(Instruction instruction) {
    /* YOUR CODE HERE */
    return 0;
}

void handle_invalid_instruction(Instruction instruction) {
    printf("Invalid Instruction: 0x%08x\n", instruction.bits); 
}

void handle_invalid_read(Address address) {
    printf("Bad Read. Address: 0x%08x\n", address);
    exit(-1);
}

void handle_invalid_write(Address address) {
    printf("Bad Write. Address: 0x%08x\n", address);
    exit(-1);
}

