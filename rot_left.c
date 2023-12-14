#include "monty_header.h"

/**
 * sq_rotl- rotate stack element to the top
 * @head: first node of stack
 * @counter: line counters.
 * Return: 0
 */

void sq_rotl(stack_t **head,  __attribute__((unused)) unsigned int counter)
{
	stack_t *tmemp_holder = *head, *aux_;

	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}
	aux_ = (*head)->next;
	aux_->prev = NULL;
	while (tmemp_holder->next != NULL)
	{
		tmemp_holder = tmemp_holder->next;
	}
	tmemp_holder->next = *head;
	(*head)->next = NULL;
	(*head)->prev = tmemp_holder;
	(*head) = aux_;
}
