#include "shell.h"

/**
 * _getEnvIndex - The return index of an environment variable
 *
 * @prnHead: first node
 * @prnname: name
 *
 * Return: index
 */
int _getEnvIndex(environment_t *prnHead, char *prnname)
{
	if (prnHead == NULL || _strcmp(prnHead->name, prnname) == 0)
		return (0);
	else
		return (_getEnvIndex(prnHead->next, prnname) + 1);
}
