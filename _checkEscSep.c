#include "shell.h"

/**
 * _checkEscapeSeparators - helps in checking sep
 * @prnchar: This is the character to compare
 * @prnEscSep:  This is the list separators to check
 *
 * Return: returns 0 on failure otherwise 1
 */
int _checkEscapeSeparators(char prnchar, char *prnEscSep)
{
	if (prnEscSep == NULL)
		return (0);

	return (_inArray(prnchar, prnEscSep));
}
