#include "monty_header.h"

/**
* execute - execute opcode
* @stack: stack of linked list
* @counter: line counter
* @file: pointer to monty file stream
* @content: line content
*
* Return: none
*/
int execute(char *content, stack_t **stack, unsigned int counter, FILE *file)
{
	instruction_t opst[] = {
				{"push", sq_push}, {"pall", sq_pall}, {"pint", sq_pint},
				{"pop", sq_pop},
				{"swap", sq_swap},
				{"add", sq_add},
				{"nop", sq_nop},
				{"sub", sq_sub},
				{"div", sq_div},
				{"mul", sq_mul},
				{"mod", sq_mod},
				{"pchar", sq_pchar},
				{"pstr", sq_pstr},
				{"rotl", sq_rotl},
				{"rotr", sq_rotr},
				{"queue", sq_queue},
				{"stack", sq_stack},
				{NULL, NULL}
				};
	unsigned int i = 0;
	char *op;

	op = strtok(content, " \n\t");
	if (op && op[0] == '#')
		return (0);
	bus_data.arg = strtok(NULL, " \n\t");
	while (opst[i].opcode && op)
	{
		if (strcmp(op, opst[i].opcode) == 0)
		{	opst[i].f(stack, counter);
			return (0);
		}
		i++;
	}
	if (op && opst[i].opcode == NULL)
	{ fprintf(stderr, "L%d: unknown instruction %s\n", counter, op);
		fclose(file);
		free(content);
		release_stack(*stack);
		exit(EXIT_FAILURE); }
	return (1);
}
