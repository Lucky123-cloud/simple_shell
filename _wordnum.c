#include "shell.h"

/**
 * _wordNumber - this is a function that returns word number
 *
 * @prnstr: character of the pointer
 * @prnSep: This are the separators
 *
 * Return: returns the number of words
 */
int _wordNumber(char *prnstr, char *prnSep)
{
	int clp = 0, count = 0;

	while (prnstr[clp] != '\0')
	{
		if (
			(
				_inArray(prnstr[clp], prnSep) != 1 ||
				prnstr[clp] != '\0'
			 ) &&
			(
				_inArray(prnstr[clp + 1], prnSep) == 1 ||
				prnstr[clp + 1] == '\0'
			)
		)
			count++;
		clp++;
	}

	return (count);
}
