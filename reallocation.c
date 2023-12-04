#include "shell.h"
/**
 * _realloc - for  memory reallocation
 * @prnpointer: prints pointer
 * @prnsizeA: check parameter 1
 * @prnsizeB: check parameter 2
 * Return: returns pointer value
 */

void *_realloc(void *prnpointer, unsigned int prnsizeA, unsigned int prnsizeB)
{
	void *a = prnpointer;

	if (prnpointer == NULL)
		return (malloc(prnsizeB));
	if (prnsizeB == prnsizeA)
		return (prnpointer);
	if (prnsizeA == 0)
	{
		free(prnpointer);
		return (NULL);
	}
	a = malloc(prnsizeA);

	if (a == NULL)
		return (NULL);
	a = _memcpy(a, prnpointer, prnsizeA);
	free(prnpointer);

	return (a);
}
