#include "shell.h"

/**
 * _createEnvNode - facilitates creating of a new node
 *
 * @prngbl: This is the global environment value
 *
 * Return: It returns a new element
 */
environment_t *_createEnvNode(char *prngbl)
{
	environment_t *new;

	if (prngbl == NULL)
		return (NULL);

	new = malloc(sizeof(environment_t));
	if (new == NULL)
		return (NULL);

	new->name = _getenvname(prngbl);
	new->value = _getenvvalue(prngbl);
	new->global = _strdup(prngbl);
	new->next = NULL;

	return (new);
}
