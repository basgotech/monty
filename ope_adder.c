#include "monty_header.h"

/**
 * sq_add - add first 2 elements of the stack
 * @head: pointer to pointer to first node
 * @counter: line counters
 * Return: none
 */

void sq_add(stack_t **head, unsigned int counter)
{
	stack_t *h_grapper;
	int len_grapper = 0, temp_holder;

	h_grapper = *head;
	while (h_grapper)
	{
		h_grapper = h_grapper->next;
		len_grapper++;
	}
	if (len_grapper < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", counter);
		fclose(bus_data.file);
		free(bus_data.content);
		release_stack(*head);
		exit(EXIT_FAILURE);
	}
	h_grapper = *head;
	temp_holder = h_grapper->n + h_grapper->next->n;
	h_grapper->next->n = temp_holder;
	*head = h_grapper->next;
	free(h_grapper);
}
