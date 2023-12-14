#include "monty_header.h"

/**
 * sq_rotl- rotate stack element to the top
 * @head: first node of stack
 * @counter: line counter
 *
 * Return: none
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

/**
 * sq_rotr - rotate stack element to the bottom
 * @head: first node of stack
 * @counter: line counter
 *
 * Return: none
 */

void sq_rotr(stack_t **head, __attribute__((unused)) unsigned int counter)
{
	stack_t *copy_of_data;

	copy_of_data = *head;
	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}
	while (copy_of_data->next)
	{
		copy_of_data = copy_of_data->next;
	}
	copy_of_data->next = *head;
	copy_of_data->prev->next = NULL;
	copy_of_data->prev = NULL;
	(*head)->prev = copy_of_data;
	(*head) = copy_of_data;
}
