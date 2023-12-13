#include "monty_header.h"

/**
 * sq_queue - print first node of queue
 * @head: first node of queue (unused)
 * @counter: line counter (unused)
 *
 * Return: none
 */

void sq_queue(stack_t **head, unsigned int counter)
{
	(void)head;
	(void)counter;

	bus_data.lifi = 1;
}

/**
 * sq_addqueue - add node to tail of queue
 * @n: new value
 * @head: head of the queue
 *
 * Return: none
 */

void sq_addqueue(stack_t **head, int n)
{
	stack_t *new_node, *temp;

	temp = *head;
	new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
		printf("Error\n");

	new_node->n = n;
	new_node->next = NULL;

	if (temp)
	{
		while (temp->next)
			temp = temp->next;
	}
	if (!temp)
	{
		*head = new_node;
		new_node->prev = NULL;
	}
	else
	{
		temp->next = new_node;
		new_node->prev = temp;
	}
}
