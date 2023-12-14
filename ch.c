#include "monty_header.h"

/**
 * sq_pchar - print the char at the top of stack
 * @head: stack head
 * @counter: line counter of char
 * Return: 0
 */

void sq_pchar(stack_t **head, unsigned int counter)
{
	stack_t *h_get;

	h_get = *head;
	if (!h_get)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", counter);
		fclose(bus_data.file);
		free(bus_data.content);
		release_stack(*head);
		exit(EXIT_FAILURE);
	}
	if (h_get->n > 127 || h_get->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", counter);
		fclose(bus_data.file);
		free(bus_data.content);
		release_stack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", h_get->n);
}
