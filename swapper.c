#include "monty_header.h"

/**
* sq_swap - swap first two elements
* @head: first node
* @counter: line counter
* Return: 0
*/

void sq_swap(stack_t **head, unsigned int counter)
{
	stack_t *h_grapper;
	int len_grapp = 0, temp_holder;

	h_grapper = *head;
	while (h_grapper)
	{
		h_grapper = h_grapper->next;
		len_grapp++;
	}
	if (len_grapp < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", counter);
		fclose(bus_data.file);
		free(bus_data.content);
		release_stack(*head);
		exit(EXIT_FAILURE);
	}
	h_grapper = *head;
	temp_holder = h_grapper->n;
	h_grapper->n = h_grapper->next->n;
	h_grapper->next->n = temp_holder;
}
