#include "shell.h"

/**
 * _setenv_val - sets an effective environ value
 *
 * @prnenv: environment of the created linked list
 * @prnm: The environment name of the simple shell
 * @prval:  The environment value of the simple shell
 * @prOvrwrt: overwrites the value given to the simple shell
 */
void _setenv_val(environment_t *prnenv, char *prnm, char *prval, int prOvrwrt)
{
	environment_t *envNode;
	char *tmp;

	if (prnm == NULL || prval == NULL)
		return;

	envNode = _getenv_var(prnenv, prnm);

	if (envNode == NULL)
	{
		tmp = _generateEnvGlobal(prnm, prval);
		_addEnvNodeEnd(&prnenv, tmp);
		free(tmp);
	}
	else if (prOvrwrt == 1)
	{
		free(envNode->value);
		envNode->value = _strdup(prval);
	}
}
