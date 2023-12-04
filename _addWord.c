#include "shell.h"

/**
 * _addingword - adds a word from the string
 *
 * @prnword: The word from the string to be added
 * @prnindex: The current index of the word to be added
 * @prnarray: array holding the added word in memory form
 */
void _addingword(char *prnword, int *prnindex, char **prnarray)
{
	prnword = _cleanstr(prnword);
	prnarray[*prnindex] = _strdup(prnword);
	free(prnword);
	*prnindex += 1;
}
