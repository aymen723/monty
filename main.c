#include "monty.h"

vars var;

/**
 * main - start
 * @ac: nbr args
 * @av: Ptr
 * Return: 0
 */
int main(int ac, char **av)
{
	char *ocode;

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}

	if (start_vars(&var) != 0)
		return (EXIT_FAILURE);

	var.file = fopen(av[1], "r");
	if (!var.file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		free_all();
		return (EXIT_FAILURE);
	}

	while (getline(&var.buff, &var.tmp, var.file) != EOF)
	{
		ocode = strtok(var.buff, " \r\t\n");
		if (ocode != NULL)
			if (call_funct(&var, ocode) == EXIT_FAILURE)
			{
				free_all();
				return (EXIT_FAILURE);
			}
		var.line_number++;
	}

	free_all();

	return (EXIT_SUCCESS);
}
