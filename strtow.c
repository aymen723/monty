#include "monty.h"
#include "lists.h"

/**
 * count_word -  nbr of words in string
 * @s: string
 *
 * Return: int
 */
int count_word(char *s)
{
	int f, count, word;

	f = 0;
	word = 0;

	for (count = 0; s[count] != '\0'; count++)
	{
		if (s[count] == ' ')
			f = 0;
		else if (f == 0)
		{
			f = 1;
			word++;
		}
	}

	return (word);
}
/**
 * **strtow - split
 * @str: string
 *
 * Return: ptr
 */
char **strtow(char *str)
{
	char **matrix, *tmp;
	int i, k = 0, len = 0, words, c = 0, start, end;

	len = strlen(str);
	words = count_word(str);
	if (words == 0)
		return (NULL);

	matrix = (char **)malloc(sizeof(char *) * (words + 1));
	if (matrix == NULL)
		return (NULL);

	for (i = 0; i <= len; i++)
	{
		if (isspace(str[i]) || str[i] == '\0' || str[i] == '\n')
		{
			if (c)
			{
				end = i;
				tmp = (char *)malloc(sizeof(char) * (c + 1));
				if (tmp == NULL)
					return (NULL);
				while (start < end)
					*tmp++ = str[start++];
				*tmp = '\0';
				matrix[k] = tmp - c;
				k++;
				c = 0;
			}
		}
		else if (c++ == 0)
			start = i;
	}

	matrix[k] = NULL;

	return (matrix);
}

/**
 * free_everything - free
 * @args: array
 */
void free_everything(char **args)
{
	int a;

	if (!args)
		return;

	for (a = 0; args[a]; a++)
		free(args[a]);

	free(args);
}
