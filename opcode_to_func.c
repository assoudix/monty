#include "monty.h"

/**
 * opcode_to_func - matches the opcode to the relevant function
 *
 * @opcode: opcode passed
 *
 * Return: pointer to the function that executes the opcode
 */
void (*opcode_to_func(char *opcode))(stack_t **stack, unsigned int line_number)
{
	int itervar;
	instruction_t instruction[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"nop", nop},
		{NULL, NULL}
	};


	for (itervar = 0; instruction[itervar].opcode != NULL; itervar++)
	{
		if (strcmp_(instruction[itervar].opcode, opcode) == 0)
			break;
	}

	return (instruction[itervar].f);
}
