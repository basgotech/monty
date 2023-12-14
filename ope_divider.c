#include "monty_header.h"

/**
 * sq_div - divide first 2 elements of the stack
 * @head: pointer to pointer to first node
 * @counter: line counter
 * Return: 0
 */

void sq_div(stack_t **head, unsigned int counter)
{
	stack_t *h_holder;
	int len_count = 0, temp_holder;

	h_holder = *head;
	while (h_holder)
	{
		h_holder = h_holder->next;
		len_count++;
	}
	if (len_count < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", counter);
		fclose(bus_data.file);
		free(bus_data.content);
		release_stack(*head);
		exit(EXIT_FAILURE);
	}
	h_holder = *head;
	if (h_holder->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", counter);
		fclose(bus_data.file);
		free(bus_data.content);
		release_stack(*head);
		exit(EXIT_FAILURE);
	}
	temp_holder = h_holder->next->n / h_holder->n;
	h_holder->next->n = temp_holder;
	*head = h_holder->next;
	free(h_holder);
}
