#include "monty.h"

everywhere_t global_var;


/**
 * check_input - checks if the file exists and if the file can
 * be opened
 *
 * @argc: argument count
 * @argv: argument vector
 * Return: file struct
 */
FILE *check_input(int argc, char *argv[])
{
	FILE *fd;

	if (argc == 1 || argc > 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fd = fopen(argv[1], "r");

	if (fd == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	return (fd);
}

/**
 * main - Entry point
 *
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	void (*f)(stack_t **stack, unsigned int line_number);
	size_t size = 256;
	char *lines[2] = {NULL, NULL};

	global_var.line = 1;
	global_var.argument = NULL;
	global_var.stack = NULL;
	global_var.file = check_input(argc, argv);
	global_var.buffer = (char *)malloc(size);
	if (global_var.buffer == NULL)
	{
		fprintf(stderr, "Memory allocation failed.\n");
		fclose(global_var.file);
		exit(EXIT_FAILURE);
	}
	while (fgets(global_var.buffer, 256, global_var.file))
	{
		lines[0] = strtok_(global_var.buffer, " \t\n");
		if (lines[0] && lines[0][0] != '#')
		{
			f = opcode_to_func(lines[0]);
			if (!f)
			{
				fprintf(stderr, "L%u: ", global_var.line);
				fprintf(stderr, "unknown instruction %s\n", lines[0]);
				free_dlistint(global_var.stack);
				free(global_var.buffer);
				fclose(global_var.file);
				exit(EXIT_FAILURE);
			}
			global_var.argument = strtok_(NULL, " \t\n");
			f(&global_var.stack, global_var.line);
		}
		global_var.line++;
	}
	free_dlistint(global_var.stack);
	free(global_var.buffer);
	fclose(global_var.file);
	return (0);
}
