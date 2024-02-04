#include "monty.h"
/**
 * pall -  printlist
 * @stack: Double llist
 * @line_number: execution
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *t = *stack;
	(void)line_number;

	if (!t)
		return;
	while (t)
	{
		printf("%d\n", t->n);
		t = t->next;
	}
}

/**
 * push - insert a new val
 * @stack: Double llist
 * @line_number: execution
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *t = NULL, *stm = *stack;
	char *num;

	num = strtok(NULL, " \r\t\n");
	if (num == NULL || (_isdigit(num) != 0 && num[0] != '-'))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		free_all();
		exit(EXIT_FAILURE);
	}
	t = malloc(sizeof(stack_t));
	if (!t)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_all();
		exit(EXIT_FAILURE);
	}
	t->n = atoi(num);
	if (var.MODE == 0 || !*stack)
	{
		t->next = *stack;
		t->prev = NULL;
		if (*stack)
			(*stack)->prev = t;
		*stack = t;
	}
	else
	{
		while (stm->next)
			stm = stm->next;
		stm->next = t;
		t->prev = stm;
		t->next = NULL;
	}
}

/**
 * pint - print lnode
 * @stack: Double llist
 * @line_number: File line execution
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (!*stack)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		free_all();
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

/**
 * pop - delete top
 * @stack: Double  llist
 * @line_number: File
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *t;

	if (!*stack)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		free_all();
		exit(EXIT_FAILURE);
	}

	t = *stack;
	*stack = t->next;
	if (t->next)
		t->next->prev = NULL;
	free(t);
}
