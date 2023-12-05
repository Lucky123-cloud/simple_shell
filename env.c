#include "shell.h"

/**
 * _env - print environement variable
 *
 * @prnd: This is the data structure
 */
void _env(appData_t *prnd)
{
	_printenv(prnd->env);
}
