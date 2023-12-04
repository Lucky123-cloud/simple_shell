#include "shell.h"

/**
 * _strlen - counts the length of the str and returns it
 *
 * @prnstr: The string to be read and length returned
 *
 * Return: Returns the length of the string
 */
int _strlen(char *prnstr)
{
	if (prnstr == NULL || *prnstr == '\0')
		return (0);
	return (_strlen(prnstr + 1) + 1);
}
