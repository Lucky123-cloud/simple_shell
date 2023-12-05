#include "shell.h"

/**
 * _printenv - helps in printing environment variables
 *
 * @prnEnviron: environment variable list
 */
void _printenv(environment_t *prnEnviron)
{
	if (prnEnviron == NULL)
		return;

	_puts(prnEnviron->name);
	_puts("=");
	if (prnEnviron->value != NULL)
		_puts(prnEnviron->value);
	_puts("\n");
	_printenv(prnEnviron->next);
}
