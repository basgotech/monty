#include "monty_header.h"

/**
 * execute - execute opcode of
* @stack: stack of linked list
* @counter: line counters
* @file: pointer to monty file streams
* @content: line content
* Return: none
*/
int execute(char *content, stack_t **stack, unsigned int counter, FILE *file)
{
	unsigned int z = 0;
	char *ope_grapper;

	instruction_t fun_grapper[] = {
				{"push", sq_push}, {"pall", sq_pall}, {"pint", sq_pint},
				{"pop", sq_pop}, {"swap", sq_swap},
				{"pchar", sq_pchar}, {"pstr", sq_pstr},
				{"rotl", sq_rotl}, {"rotr", sq_rotr}, {"add", sq_add},
				{"nop", sq_nop}, {"sub", sq_sub}, {"div", sq_div},
				{"mul", sq_mul}, {"mod", sq_mod}, {"queue", sq_queue},
				{"stack", sq_stack}, {NULL, NULL}
				};

	ope_grapper = strtok(content, " \n\t");
	if (ope_grapper && ope_grapper[0] == '#')
	{
		return (0);
	}
	bus_data.arg = strtok(NULL, " \n\t");
	while (fun_grapper[z].opcode && ope_grapper)
	{
		if (strcmp(ope_grapper, fun_grapper[z].opcode) == 0)
		{	fun_grapper[z].f(stack, counter);
			return (0);
		}
		z++;
	}
	if (ope_grapper && fun_grapper[z].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", counter, ope_grapper);
		fclose(file);
		free(content);
		release_stack(*stack);
		exit(EXIT_FAILURE);
	}
	return (1);
}
