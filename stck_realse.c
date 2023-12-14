#include "monty_header.h"

/**
 * release_stack - free doubly linked list.
 * @head: first node of stacks
 * Return: 0
 */

void release_stack(stack_t *head)
{
	stack_t *temp_holder;

	temp_holder = head;
	while (head)
	{
		temp_holder = head->next;
		free(head);
		head = temp_holder;
	}
}
