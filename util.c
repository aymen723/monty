#include "monty.h"

/**
 * start_vars - rand
 * @var: gv
 * Return: 0
 */
int start_vars(vars *var)
{
	var->file = NULL;
	var->buff = NULL;
	var->tmp = 0;
	var->dict = create_instru();
	if (var->dict == NULL)
		return (EXIT_FAILURE);
	var->head = NULL;
	var->line_number = 1;
	var->MODE = 0;

	return (EXIT_SUCCESS);
}

/**
 * create_instru - Create new functions
 * Return: dic pointer
 */
instruction_t *create_instru()
{
	instruction_t *ptr = malloc(sizeof(instruction_t) * 18);

	if (!ptr)
	{
		fprintf(stderr, "Error: malloc failed\n");
		return (NULL);
	}
	ptr[0].opcode = "pall", ptr[0].f = pall;
	ptr[1].opcode = "push", ptr[1].f = push;
	ptr[2].opcode = "pint", ptr[2].f = pint;
	ptr[3].opcode = "pop", ptr[3].f = pop;
	ptr[4].opcode = "swap", ptr[4].f = swap;
	ptr[5].opcode = "add", ptr[5].f = add;
	ptr[6].opcode = "nop", ptr[6].f = NULL;
	ptr[7].opcode = "sub", ptr[7].f = sub;
	ptr[8].opcode = "div", ptr[8].f = divi;
	ptr[17].opcode = NULL, ptr[17].f = NULL;

	return (ptr);
}

/**
 * call_funct - call func
 * @var: gv
 * @opcode: Command
 * Return: None
 */
int call_funct(vars *var, char *opcode)
{
	int a;

	for (a = 0; var->dict[a].opcode; a++)
		if (strcmp(opcode, var->dict[a].opcode) == 0)
		{
			if (!var->dict[a].f)
				return (EXIT_SUCCESS);
			var->dict[a].f(&var->head, var->line_number);
			return (EXIT_SUCCESS);
		}
	if (strlen(opcode) != 0 && opcode[0] != '#')
	{
		fprintf(stderr, "L%u: unknown instruction %s\n",
				var->line_number, opcode);
		return (EXIT_FAILURE);
	}

	return (EXIT_SUCCESS);
}

/**
 * free_all - Clean
 * Return: None
 */
void free_all(void)
{
	if (var.buff != NULL)
		free(var.buff);
	if (var.file != NULL)
		fclose(var.file);
	free(var.dict);
	if (var.head != NULL)
	{
		while (var.head->next != NULL)
		{
			var.head = var.head->next;
			free(var.head->prev);
		}
		free(var.head);
	}
}

/**
 * _isdigit - Clean
 * @string: Num
 * Return: 0
 */
int _isdigit(char *string)
{
	int a;

	for (a = 0; string[a]; a++)
	{
		if (string[a] < 48 || string[a] > 57)
			return (1);
	}
	return (0);
}
