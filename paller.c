#include "monty_header.h"

/**
* sq_pall - print everything in stack
* @head: pointer to pointer of first node
* @counter: line counter
* Return: 0
*/

void sq_pall(stack_t **head, unsigned int counter)
{
	stack_t *h_grapper;
	(void)counter;

	h_grapper = *head;
	if (h_grapper == NULL)
	{
		return;
	}
	while (h_grapper)
	{
		printf("%d\n", h_grapper->n);
		h_grapper = h_grapper->next;
	}
}
