#include "shell.h"

/**
 * _getenvvalue - the main function that return environment value
 *
 * @prnvar: This is the environment name
 *
 * Return: environment value
 */
char *_getenvvalue(char *prnvar)
{
	char **tmp, *name;

	tmp = _strtow(prnvar, ENV_SEPARATOR, NULL);

	if (tmp == NULL)
		return (NULL);

	name = _strdup(tmp[1]);
	_freeCharDoublePointer(tmp);
	tmp = NULL;

	return (name);
}
