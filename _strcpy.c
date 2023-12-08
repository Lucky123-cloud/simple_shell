#include "shell.h"

/**
 * _strcpy - cpy str pointed to by src,
 *               plus terminating null byte (\0),
 *               to the buffer pointed to by dest
 *
 * @prndest: 1st character pointer to the string
 * @prnsrc: 2nd character pointer to the string
 *
 * Return: returns character pointer (char*)
 */
char *_strncpy(char *prndest, char *prnsrc)
{
	int clp, size = _strlen(prnsrc);

	for (clp = 0; clp < size; clp++)
	{
		prndest[clp] = prnsrc[clp];
	}

	prndest[size] = '\0';

	return (prndest);
}
