#include "monty_header.h"

/**
 * sq_push - function that adds node to the stack
 * @head: double head pointer to the stack
 * @counter: line count
 *
 * Return: nothing
 */
void sq_push(stack_t **head, unsigned int counter)
{
	int i, m = 0, flag = 0;

	if (bus_data.arg)
	{
		if (bus_data.arg[0] == '-')
			m++;
		for (; bus_data.arg[m] != '\0'; m++)
		{
			if (bus_data.arg[m] > 57 || bus_data.arg[m] < 48)
				flag = 1; }
		if (flag == 1)
		{ fprintf(stderr, "L%d: usage: push integer\n", counter);
			fclose(bus_data.file);
			free(bus_data.content);
			release_stack(*head);
			exit(EXIT_FAILURE); }}
	else
	{ fprintf(stderr, "L%d: usage: push integer\n", counter);
		fclose(bus_data.file);
		free(bus_data.content);
		release_stack(*head);
		exit(EXIT_FAILURE); }
	i = atoi(bus_data.arg);
	if (bus_data.lifi == 0)
		sq_addnode(head, i);
	else
		sq_addqueue(head, i);
}
