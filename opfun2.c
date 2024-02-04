#include "monty.h"

/**
 * swap - Delete the top
 * @stack: double llist
 * @line_number: file
 */
void swap(stack_t **stack, unsigned int line_number)
{
	int t;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n",
				line_number);
		free_all();
		exit(EXIT_FAILURE);
	}
	t = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = t;
}

/**
 * add - add at the top
 * @stack: double llist
 * @line_number: File
 */
void add(stack_t **stack, unsigned int line_number)
{
	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n",
				line_number);
		free_all();
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n = (*stack)->next->n + (*stack)->n;
	pop(stack, line_number);
}

/**
 * sub - func to subtrack
 * @stack: double llist
 * @line_number: counter
 */
void sub(stack_t **stack, unsigned int line_number)
{
	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n",
				line_number);
		free_all();
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n = (*stack)->next->n - (*stack)->n;
	pop(stack, line_number);
}

/**
 * divi - func divid
 * @stack: double llist
 * @line_number: File
 */
void divi(stack_t **stack, unsigned int line_number)
{
	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n",
				line_number);
		free_all();
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		free_all();
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n = (*stack)->next->n / (*stack)->n;
	pop(stack, line_number);
}
