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
	stack_t *new_node_, *temp_holder;

	temp_holder = *head;
	new_node_ = malloc(sizeof(stack_t));

	if (new_node_ == NULL)
		printf("Error\n");

	new_node_->n = n;
	new_node_->next = NULL;

	if (temp_holder)
	{
		while (temp_holder->next)
		{
			temp_holder = temp_holder->next;
		}
	}
	if (!temp_holder)
	{
		*head = new_node_;
		new_node_->prev = NULL;
	}
	else
	{
		temp_holder->next = new_node_;
		new_node_->prev = temp_holder;
	}
}
