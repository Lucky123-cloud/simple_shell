#include "shell.h"

/**
 * _inArray - Tries to find a char in an array
 *
 * @prnchar: The input character to be searched
 * @prnarray: The array where the character searching is taking place
 *
 * Return: returns a value true is successfully searched
 */
int _inArray(char prnchar, char *prnarray)
{
	int clp;

	if (prnarray == NULL)
		return (0);

	for (clp = 0; prnarray[clp] != '\0'; clp++)
		if (prnarray[clp] == prnchar)
			return (1);

	return (0);
}
