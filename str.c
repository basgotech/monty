#include "monty_header.h"

/**
 * sq_pstr - print string at the top of stack
 * @head: first node of linked list
 * @counter: line counter
 *
 * Return: none
 */

void sq_pstr(stack_t **head, unsigned int counter)
{
	stack_t *h_data;
	(void)counter;

	h_data = *head;
	while (h_data)
	{
		if (h_data->n > 127 || h_data->n <= 0)
		{
			break;
		}
		printf("%c", h_data->n);
		h_data = h_data->next;
	}
	printf("\n");
}
