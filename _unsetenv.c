#include "shell.h"

/**
 * _unsetenv - This function helps in unsetting the environment variable
 *
 * @prndata: data structure
 * @prnname: environment name
 */
void _unsetenv(appData_t *prndata, char *prnname)
{
	_deleteEnvNode(prndata->env, prnname);
}
