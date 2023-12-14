#include "monty_header.h"

/**
 * sq_sub - subtract 2 elements of the stack
 * @head: pointer to pointer to first node
 * @counter: line counters
 * Return: 0
 */

void sq_sub(stack_t **head, unsigned int counter)
{
	stack_t *temp_holder;
	int sub, nd;

	temp_holder = *head;
	for (nd = 0; temp_holder != NULL; nd++)
		temp_holder = temp_holder->next;

	if (nd < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", counter);
		fclose(bus_data.file);
		free(bus_data.content);
		release_stack(*head);
		exit(EXIT_FAILURE);
	}
	temp_holder = *head;
	sub = temp_holder->next->n - temp_holder->n;
	temp_holder->next->n = sub;
	*head = temp_holder->next;
	free(temp_holder);
}
