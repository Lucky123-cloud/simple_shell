#include "shell.h"

/**
 * _checkSeparators - helps in checking of one of the sepators or EOF char
 * @prnchar: This are some of the character to compare
 * @prnseparators: This are list of separators:
 *
 * Return: returns 0 on  falilure otherwise 1
 */
int _checkSeparators(char prnchar, char *prnseparators)
{
	if (prnseparators == NULL)
		return (0);

	return (
		_inArray(prnchar, prnseparators) == 1 ||
		prnchar == '\0'
	);
}
