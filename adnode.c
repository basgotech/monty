#include "monty_header.h"

/**
* sq_addnode - add node to top of stack.
* @head: first node
* @n: new value to node
* Return: none
*/

void sq_addnode(stack_t **head, int n)
{
	stack_t *new_node_, *temp_holder;

	temp_holder = *head;
	new_node_ = malloc(sizeof(stack_t));

	if (new_node_ == NULL)
	{
		printf("Error\n");
		exit(0);
	}
	if (temp_holder)
		temp_holder->prev = new_node_;

	new_node_->n = n;
	new_node_->next = *head;
	new_node_->prev = NULL;
	*head = new_node_;
}
