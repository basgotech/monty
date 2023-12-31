#ifndef MONTY_HEADER_H
#define MONTY_HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct bus_s - variables -args, file, line content
 * @arg: value
 * @file: pointer to monty file
 * @content: line content
 * @lifi: flag change stack <-> queue
 *
 * Description: carries values through the program
 */
typedef struct bus_s
{
	char *arg;
	FILE *file;
	char *content;
	int lifi;
}  bus_t;
extern bus_t bus_data;
ssize_t getline(char **lineptr, size_t *n, FILE *stream);
void release_stack(stack_t *head);
int execute(char *content, stack_t **head, unsigned int counter, FILE *file);
void sq_div(stack_t **head, unsigned int counter);
void sq_mul(stack_t **head, unsigned int counter);
void sq_mod(stack_t **head, unsigned int counter);
void sq_pchar(stack_t **head, unsigned int counter);
void sq_pstr(stack_t **head, unsigned int counter);
void sq_rotl(stack_t **head, unsigned int counter);
void sq_rotr(stack_t **head, __attribute__((unused)) unsigned int counter);
void sq_addnode(stack_t **head, int n);
void sq_addqueue(stack_t **head, int n);
void sq_queue(stack_t **head, unsigned int counter);
void sq_stack(stack_t **head, unsigned int counter);
int _atoi(char *str);
void sq_push(stack_t **head, unsigned int number);
void sq_pall(stack_t **head, unsigned int number);
void sq_pint(stack_t **head, unsigned int number);
void sq_pop(stack_t **head, unsigned int counter);
void sq_swap(stack_t **head, unsigned int counter);
void sq_nop(stack_t **head, unsigned int counter);
void sq_add(stack_t **head, unsigned int counter);
void sq_sub(stack_t **head, unsigned int counter);

#endif
