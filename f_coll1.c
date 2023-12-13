#include "monty_header.h"

/**
 * sq_pop - print top node on stack
 * @head: pointer to pointer of first node
 * @counter: line counter
 *
 * Return: none
 */

void sq_pop(stack_t **head, unsigned int counter)
{
	stack_t *h;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", counter);
		fclose(bus_data.file);
		free(bus_data.content);
		release_stack(*head);
		exit(EXIT_FAILURE);
	}

	h = *head;
	*head = h->next;
	free(h);
}

/**
 * sq_pint - print top node on stack
 * @head: pointer to pointer of first node
 * @counter: line counter
 *
 * Return: none
 */

void sq_pint(stack_t **head, unsigned int counter)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", counter);
		fclose(bus_data.file);
		free(bus_data.content);
		release_stack(*head);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*head)->n);
}

/**
 * f_nop - do nothing
 * @head: pointer to pointer of first node
 * @counter: line counter
 *
 * Return: none
 */

void sq_nop(stack_t **head, unsigned int counter)
{
	(void) counter;
	(void) head;
}
