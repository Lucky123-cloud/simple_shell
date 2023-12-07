#include "shell.h"

/**
 * _getword - function that returns word
 *
 * @prnGlobal: This is the character pointer
 * @prnOffset: This is the start of the word
 * @prnSize: prints length
 *
 * Return: returns the number of Words
 */
char *_getword(char *prnGlobal, int prnOffset, int prnSize)
{
	char *w;
	int clp;

	w = malloc(sizeof(char) * prnSize + 1);

	if (w == NULL)
		return (NULL);

	for (clp = 0; clp < (prnSize); clp++)
		w[clp] = prnGlobal[prnOffset + clp];

	w[clp] = '\0';

	return (w);
}
