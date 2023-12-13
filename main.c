#include "monty_header.h"
#define _GNU_SOURCE

bus_t bus_data = {NULL, NULL, NULL, 0};

/**
* main - monty code interpreter
* @argc: argument counter
* @argv: argument vector
*
* Return: always 0
*/
int main(int argc, char *argv[])
{
	char *content;
	FILE *file;
	size_t size = 0;
	ssize_t read_line = 1;
	stack_t *stack = NULL;
	unsigned int counter = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	bus_data.file = file;

	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (read_line > 0)
	{
		content = NULL;
		read_line = getline(&content, &size, file);
		bus_data.content = content;
		counter++;

		if (read_line > 0)
			execute(content, &stack, counter, file);

		free(content);
	}

	release_stack(stack);
	fclose(file);
	return (0);
}
