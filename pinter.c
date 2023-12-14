#include "monty_header.h"

/**
 * sq_pint - print top node on stack
 * @head: pointer to pointer of first node
 * @counter: line counters
 * Return: 0
 */

void sq_pint(stack_t **head, unsigned int counter)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", counter);
		fclose(bus_data.file);
		free(bus_data.content);
		release_stack(*head);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*head)->n);
}
