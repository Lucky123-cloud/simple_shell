#include "shell.h"

/**
 * _getenvname - function that brings(returns) environment name
 *
 * @prnvar:  This is the name of environment
 *
 * Return: This function returns environment name
 */
char *_getenvname(char *prnvar)
{
	char **tmp, *name;

	tmp = _strtow(prnvar, ENV_SEPARATOR, NULL);

	if (tmp == NULL)
		return (NULL);

	name = _strdup(tmp[0]);
	_freeCharDoublePointer(tmp);
	tmp = NULL;

	return (name);
}
