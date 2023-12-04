#include "shell.h"

/**
 * _strdup - a ptr to a newly allocated space in mem,
 * containing a cpy of the string given as a parameter.
 *
 * @prnstr: character pointer to be copied
 *
 * Return: Returns a new character pointer to the console
 * for other processes
 */
char *_strdup(char *prnstr)
{
	char *str;
	int clp;

	if (prnstr == NULL)
		return (NULL);

	str = malloc(sizeof(char) * (_strlen(prnstr) + 1));

	if (str == NULL)
		return (NULL);

	for (clp = 0; clp < _strlen(prnstr) + 1; clp++)
		str[clp] = prnstr[clp];

	return (str);
}
