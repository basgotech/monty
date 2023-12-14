#include "monty_header.h"

/**
 * release_stack - free doubly linked list
 * @head: first node of stack
 * Return: none
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

/**
 * sq_stack - free stack
 * @head: first node(unused)
 * @counter: line counter (unused)
 *
 * Return: none
*/

void sq_stack(stack_t **head, unsigned int counter)
{
	(void)head;
	(void)counter;

	bus_data.lifi = 0;
}
