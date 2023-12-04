#include "shell.h"

/**
 * _freeCharDoublePointer - function that free memory of a double pointer
 *
 * @prnptr: This is the double pointer being freed
 */
void _freeCharDoublePointer(char **prnptr)
{
	int clp = 0;

	if (prnptr == NULL)
		return;

	while (prnptr[clp] != NULL)
	{
		free(prnptr[clp]);
		prnptr[clp] = NULL;
		clp++;
	}
	free(prnptr);
}
