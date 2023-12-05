#include "shell.h"

/**
 * _setEnvironment - helps in setting environment variable
 *
 * @prnd:The way the data is stored in mem data's structure
 */
void _setEnvironment(appData_t *prnd)
{
	if (prnd == NULL)
		return;

	if (prnd->arguments == NULL)
		return;

	if (prnd->arguments[1] == NULL || prnd->arguments[2] == NULL)
		return;

	_setenv_val(prnd->env, prnd->arguments[1], prnd->arguments[2], 1);
}
