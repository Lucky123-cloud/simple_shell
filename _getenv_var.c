#include "shell.h"

/**
 * _getenv_var - helps the user to get the enviroment variable
 *
 * @prnenviron: first node of the envrin variable
 * @prnname: get the environment variable name
 *
 * Return: returns environment variable node
 */
environment_t *_getenv_var(environment_t *prnenviron, char *prnname)
{
	if (prnenviron == NULL)
		return (NULL);

	if (_strcmp(prnenviron->name, prnname) == 0)
		return (prnenviron);

	return (_getenv_var(prnenviron->next, prnname));
}
