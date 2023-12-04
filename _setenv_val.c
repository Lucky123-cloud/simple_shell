#include "shell.h"

/**
 * _setenv_val - sets an effective environ value
 *
 * @prnenviron: environment of the created linked list
 * @prnname: The environment name of the simple shell
 * @prnval:  The environment value of the simple shell
 * @prnoverwrite: overwrites the value given to the simple shell
 */
void _setenv_val(
	environment_t *prnenviron,
	char *prnname,
	char *prnval,
	int prnoverwrite
) {
	environment_t *envNode;
	char *tmp;

	if (prnname == NULL || prnval == NULL)
		return;

	envNode = _getenv_var(prnenviron, prnname);

	if (envNode == NULL)
	{
		tmp = _generateEnvGlobal(prnname, prnval);
		_addEnvNodeEnd(&prnenviron, tmp);
		free(tmp);
	}
	else if (prnoverwrite == 1)
	{
		free(envNode->value);
		envNode->value = _strdup(prnval);
	}
}
