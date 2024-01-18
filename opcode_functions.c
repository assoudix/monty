#include "monty.h"


/**
 * push - pushes an element on stack
 *
 * @stack: head of the stack
 * @line_number: line number
 * Return: no return
 */
void push(stack_t **stack, unsigned int line_number)
{
	int i, val;

	if (!global_var.argument)
	{
		fprintf(stderr, "L%u: ", line_number);
		fprintf(stderr, "usage: push integer\n");
		free_dlistint(global_var.stack);
		free(global_var.buffer);
		fclose(global_var.file);
		exit(EXIT_FAILURE);
	}

	for (i = 0; global_var.argument[i] != '\0'; i++)
	{
		if (!isdigit(global_var.argument[i]) && global_var.argument[i] != '-')
		{
			fprintf(stderr, "L%u: ", line_number);
			fprintf(stderr, "usage: push integer\n");
			free_dlistint(global_var.stack);
			free(global_var.buffer);
			fclose(global_var.file);
			exit(EXIT_FAILURE);
		}
	}

	val = atoi(global_var.argument);

	add_dnodeint(stack, val);
}

/**
 * pall - prints all elements on stack
 *
 * @stack: head of the linked list
 * @line_number: line numbers
 * Return: no return
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp_stack;
	(void)line_number;

	temp_stack = *stack;

	while (temp_stack)
	{
		printf("%d\n", temp_stack->n);
		temp_stack = temp_stack->next;
	}
}

/**
 * pint - peeks stack
 *
 * @stack: head of the linked list
 * @line_number: line number
 * Return: no return
 */
void pint(stack_t **stack, unsigned int line_number)
{
	(void)line_number;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: ", line_number);
		fprintf(stderr, "can't pint, stack empty\n");
		free_dlistint(global_var.stack);
		free(global_var.buffer);
		fclose(global_var.file);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}

/**
 * pop - pops the stack
 *
 * @stack: head of the linked list
 * @line_number: line number
 * Return: no return
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp_stack;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		free_dlistint(global_var.stack);
		free(global_var.buffer);
		fclose(global_var.file);
		exit(EXIT_FAILURE);
	}
	temp_stack = *stack;
	*stack = (*stack)->next;
	free(temp_stack);
}

/**
 * nop - NOOOOOOOOOOOPPPPE
 *
 * @stack: head of the linked list
 * @line_number: line number
 * Return: no return
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
