#include "shell.h"

/**
 * _cleanstr - removes unnecesaarily put trailing white spaces
 * @prnstr: Str input by the user and is to be cleaned
 * Return: A clean string whitespace free is returned
 */
char *_cleanstr(char *prnstr)
{
	int clps = 0, clpe = 0, size = 0;
	char *str;

	if (prnstr == NULL)
		return (NULL);

	size = _strlen(prnstr);

	while (_inArray(prnstr[clps], " ") == 1)
		clps++;

	clpe = size - 1;
	while (_inArray(prnstr[clpe], " ") == 1)
		clpe--;
	clpe = size - 1 - clpe;

	str = _calloc(sizeof(char), size - clps - clpe + 1);
	_strncpy(str, (prnstr + clps), size - clps - clpe);
	str[size - clps - clpe] = '\0';

	prnstr = _realloc(
		prnstr,
		size,
		sizeof(char) * (size - clps - clpe + 1)
	);
	_strcpy(prnstr, str);
	prnstr[size - clps - clpe] = '\0';
	free(str);
	return (prnstr);
}

