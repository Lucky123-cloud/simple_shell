#include "shell.h"

/**
 * _initEnvData - This is init environment linked list
 *
 * @prndata: This is how the data is stored(data structure)
 */
void _initEnvData(appData_t *prndata)
{
	int clp = 0;
	environment_t *new;

	if (prndata == NULL)
		return;

	while (environ[clp] != NULL)
	{
		new = _addEnvNodeEnd(&prndata->env, environ[clp]);

		if (new == NULL)
		{
			free(prndata->env);
			prndata->env = NULL;
			return;
		}

		clp++;
	}
}
