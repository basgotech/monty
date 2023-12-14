#include "monty_header.h"
#define _GNU_SOURCE

bus_t bus_data = {NULL, NULL, NULL, 0};

/**
* main - monty code interpreter
* @argc: argument counter
* @argv: argument vector.
* Return: always 0
*/
int main(int argc, char *argv[])
{
	char *content_grapper;
	FILE *f_grapper;
	size_t get_len_si = 0;
	ssize_t rl_grapper = 1;
	stack_t *stack = NULL;
	unsigned int cout_of_cm = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	f_grapper = fopen(argv[1], "r");
	bus_data.file = f_grapper;

	if (!f_grapper)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (rl_grapper > 0)
	{
		content_grapper = NULL;
		rl_grapper = getline(&content_grapper, &get_len_si, f_grapper);
		bus_data.content = content_grapper;
		cout_of_cm++;

		if (rl_grapper > 0)
		{
			execute(content_grapper, &stack, cout_of_cm, f_grapper);
		}

		free(content_grapper);
	}

	release_stack(stack);
	fclose(f_grapper);
	return (0);
}
