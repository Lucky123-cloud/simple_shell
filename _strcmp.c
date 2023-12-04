#include "shell.h"

/**
 * _strcmp - finds out and compares two or more strings
 *
 * @prnstr1: first character pointer
 * @prnstr2: second character pointer
 *
 * Return: difference between ascii number from the strings
 */
int _strcmp(char *prnstr1, char *prnstr2)
{
	int len;

	for (len = 0; prnstr1[len] != '\0'; len++)
	{
		if (prnstr1[len] - prnstr2[len] != 0)
			return (prnstr1[len] - prnstr2[len]);
	}

	return (0);
}
