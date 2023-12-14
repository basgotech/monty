#include "monty_header.h"

/**
 * sq_add - add first 2 elements of the stack
 * @head: pointer to pointer to first node
 * @counter: line counter
 *
 * Return: none
 */

void sq_add(stack_t **head, unsigned int counter)
{
	stack_t *h_grapper;
	int len_grapper = 0, temp_holder;

	h_grapper = *head;
	while (h_grapper)
	{
		h_grapper = h_grapper->next;
		len_grapper++;
	}
	if (len_grapper < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", counter);
		fclose(bus_data.file);
		free(bus_data.content);
		release_stack(*head);
		exit(EXIT_FAILURE);
	}
	h_grapper = *head;
	temp_holder = h_grapper->n + h_grapper->next->n;
	h_grapper->next->n = temp_holder;
	*head = h_grapper->next;
	free(h_grapper);
}

/**
 * sq_sub - subtract 2 elements of the stack
 * @head: pointer to pointer to first node
 * @counter: line counter
 *
 * Return: none
 */

void sq_sub(stack_t **head, unsigned int counter)
{
	stack_t *temp_holder;
	int sub, nd;

	temp_holder = *head;
	for (nd = 0; temp_holder != NULL; nd++)
		temp_holder = temp_holder->next;

	if (nd < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", counter);
		fclose(bus_data.file);
		free(bus_data.content);
		release_stack(*head);
		exit(EXIT_FAILURE);
	}
	temp_holder = *head;
	sub = temp_holder->next->n - temp_holder->n;
	temp_holder->next->n = sub;
	*head = temp_holder->next;
	free(temp_holder);
}

/**
 * sq_mul - multiply first 2 elements of the stack
 * @head: pointer to pointer to first node
 * @counter: line counter
 *
 * Return: none
 */

void sq_mul(stack_t **head, unsigned int counter)
{
	stack_t *h_grapper;
	int len_count = 0, temp_holder;

	h_grapper = *head;
	while (h_grapper)
	{
		h_grapper = h_grapper->next;
		len_count++;
	}
	if (len_count < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", counter);
		fclose(bus_data.file);
		free(bus_data.content);
		release_stack(*head);
		exit(EXIT_FAILURE);
	}
	h_grapper = *head;
	temp_holder = h_grapper->next->n * h_grapper->n;
	h_grapper->next->n = temp_holder;
	*head = h_grapper->next;
	free(h_grapper);
}

/**
 * sq_div - divide first 2 elements of the stack
 * @head: pointer to pointer to first node
 * @counter: line counter
 *
 * Return: none
 */

void sq_div(stack_t **head, unsigned int counter)
{
	stack_t *h_holder;
	int len_count = 0, temp_holder;

	h_holder = *head;
	while (h_holder)
	{
		h_holder = h_holder->next;
		len_count++;
	}
	if (len_count < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", counter);
		fclose(bus_data.file);
		free(bus_data.content);
		release_stack(*head);
		exit(EXIT_FAILURE);
	}
	h_holder = *head;
	if (h_holder->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", counter);
		fclose(bus_data.file);
		free(bus_data.content);
		release_stack(*head);
		exit(EXIT_FAILURE);
	}
	temp_holder = h_holder->next->n / h_holder->n;
	h_holder->next->n = temp_holder;
	*head = h_holder->next;
	free(h_holder);
}

/**
 * sq_mod - compute modulos of two elements in stack
 * @head: pointer to pointer to first node
 * @counter: line counter
 *
 * Return: none
 */

void sq_mod(stack_t **head, unsigned int counter)
{
	stack_t *h_holder;
	int len_count = 0, temp_holder;

	h_holder = *head;
	while (h_holder)
	{
		h_holder = h_holder->next;
		len_count++;
	}
	if (len_count < 2)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", counter);
		fclose(bus_data.file);
		free(bus_data.content);
		release_stack(*head);
		exit(EXIT_FAILURE);
	}
	h_holder = *head;
	if (h_holder->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", counter);
		fclose(bus_data.file);
		free(bus_data.content);
		release_stack(*head);
		exit(EXIT_FAILURE);
	}
	temp_holder = h_holder->next->n % h_holder->n;
	h_holder->next->n = temp_holder;
	*head = h_holder->next;
	free(h_holder);
}
