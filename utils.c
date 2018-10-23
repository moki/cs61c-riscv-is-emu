#include "utils.h"
#include <stdio.h>
#include <stdlib.h>

/* Sign extends the given field to a 32-bit integer where field is
 * interpreted an n-bit integer. */
int sign_extend_number(unsigned int field, unsigned int n) {
	unsigned int n_field_bits = field & ((1U << n) - 1);

	// 1 -> negative; 0 -> positive
	unsigned int msb = field & (1U << (n - 1));

	unsigned int mask = msb ? ((1UL << 32) - 1) : 0;

	mask <<= n;

	mask ^= n_field_bits;

	return mask;
}

/* Unpacks the 32-bit machine code instruction given into the correct
 * type within the instruction struct */
Instruction parse_instruction(uint32_t instruction_bits) {
	Instruction instruction;

	instruction.opcode = instruction_bits & ((1U << 7) - 1);
	instruction_bits >>= 7;

	switch (instruction.opcode) {
		// R-Type
		case 0x33:
			instruction.rtype.rd = instruction_bits & ((1U << 5) - 1);
			instruction_bits >>= 5;

			instruction.rtype.funct3 = instruction_bits & ((1U << 3) - 1);
			instruction_bits >>= 3;

			instruction.rtype.rs1 = instruction_bits & ((1U << 5) - 1);
			instruction_bits >>= 5;

			instruction.rtype.rs2 = instruction_bits & ((1U << 5) - 1);
			instruction_bits >>= 5;

			instruction.rtype.funct7 = instruction_bits & ((1U << 7) - 1);

			break;
		// I-Type
		case 0x03:
		case 0x13:
		case 0x73:
			instruction.itype.rd = instruction_bits & ((1U << 5) - 1);
			instruction_bits >>= 5;

			instruction.itype.funct3 = instruction_bits & ((1U << 3) - 1);
			instruction_bits >>= 3;

			instruction.itype.rs1 = instruction_bits & ((1U << 5) - 1);
			instruction_bits >>= 5;

			instruction.itype.imm = instruction_bits & ((1U << 12) - 1);

			break;
		// S-Type
		case 0x23:
			instruction.stype.imm5 = instruction_bits & ((1U << 5) - 1);
			instruction_bits >>= 5;

			instruction.stype.funct3 = instruction_bits & ((1U << 3) - 1);
			instruction_bits >>= 3;

			instruction.stype.rs1 = instruction_bits & ((1U << 5) - 1);
			instruction_bits >>= 5;

			instruction.stype.rs2 = instruction_bits & ((1U << 5) - 1);
			instruction_bits >>= 5;

			instruction.stype.imm7 = instruction_bits & ((1U << 7) - 1);

			break;
		// SB-Type
		case 0x63:
			instruction.sbtype.imm5 = instruction_bits & ((1U << 5) - 1);
			instruction_bits >>= 5;

			instruction.sbtype.funct3 = instruction_bits & ((1U << 3) - 1);
			instruction_bits >>= 3;

			instruction.sbtype.rs1 = instruction_bits & ((1U << 5) - 1);
			instruction_bits >>= 5;

			instruction.sbtype.rs2 = instruction_bits & ((1U << 5) - 1);
			instruction_bits >>= 5;

			instruction.rtype.funct7 = instruction_bits & ((1U << 7) - 1);

			break;
		// U-Type
		case 0x37:
			instruction.utype.rd = instruction_bits & ((1U << 5) - 1);
			instruction_bits >>= 5;

			instruction.utype.imm = instruction_bits & ((1U << 20) - 1);

			break;
		// UJ-Type
		case 0x6f:
			instruction.ujtype.rd = instruction_bits & ((1U << 5) - 1);
			instruction_bits >>= 5;

			instruction.ujtype.imm = instruction_bits & ((1U << 20) - 1);
			break;
		default:
			exit(EXIT_FAILURE);
	}

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

