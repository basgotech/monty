#include "monty_header.h"

/**
 * sq_mul - multiply first 2 elements of the stack
 * @head: pointer to pointer to first node
 * @counter: line counters
 * Return: 0
 */

void sq_mul(stack_t **head, unsigned int counter)
{
	stack_t *h_grapper;
	int len_count = 0, temp_holder;

	h_grapper = *head;
	while (h_grapper)
	{
		h_grapper = h_grapper->next;
		len_count++;
	}
	if (len_count < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", counter);
		fclose(bus_data.file);
		free(bus_data.content);
		release_stack(*head);
		exit(EXIT_FAILURE);
	}
	h_grapper = *head;
	temp_holder = h_grapper->next->n * h_grapper->n;
	h_grapper->next->n = temp_holder;
	*head = h_grapper->next;
	free(h_grapper);
}
