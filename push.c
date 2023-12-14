#include "monty_header.h"

/**
 * sq_push - function that adds node to the stack
 * @head: double head pointer to the stack
 * @counter: line counts
 * Return: 0
 */
void sq_push(stack_t **head, unsigned int counter)
{
	int x, y = 0, flag_grapper = 0;

	if (bus_data.arg)
	{
		if (bus_data.arg[0] == '-')
			y++;
		for (; bus_data.arg[y] != '\0'; y++)
		{
			if (bus_data.arg[y] > 57 || bus_data.arg[y] < 48)
				flag_grapper = 1; }
		if (flag_grapper == 1)
		{ fprintf(stderr, "L%d: usage: push integer\n", counter);
			fclose(bus_data.file);
			free(bus_data.content);
			release_stack(*head);
			exit(EXIT_FAILURE); }}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", counter);
		fclose(bus_data.file);
		free(bus_data.content);
		release_stack(*head);
		exit(EXIT_FAILURE); }
	x = _atoi(bus_data.arg);
	if (bus_data.lifi == 0)
		sq_addnode(head, x);
	else
		sq_addqueue(head, x);
}
