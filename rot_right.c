#include "monty_header.h"

/**
 * sq_rotr - rotate stack element to the bottom
 * @head: first node of stack
 * @counter: line counters
 * Return: 0
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
