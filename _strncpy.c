#include "shell.h"

/**
 * _strncpy - Helps in printing and copies a string
 *
 * @prndest: character pointer to the memory
 * @prnsrc: character  pointers to the memory
 * @prnlim: The number of chacters provided
 *
 * Return: string
 */
char *_strncpy(char *prndest, char *prnsrc, int prnlim)
{
	int length, size_s;

	size_s = _strlen(prnsrc);

	for (length = 0; length < prnlim; length++)
	{
		prndest[length] = (length <= size_s) ? prnsrc[length] : '\0';
	}

	return (prndest);
}
