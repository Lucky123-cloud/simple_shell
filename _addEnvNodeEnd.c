
#include "shell.h"

/**
 * _addEnvNodeEnd - This adds a new node from the lastones
 *
 * @prmHeadNode: The is the head node or the first node
 * @prngbl: This global environment value
 *
 * Return: This is the last element of the nodes
 */
environment_t *_addEnvNodeEnd(
	environment_t **prmHeadNode,
	char *prngbl
) {
	environment_t *new, *last;

	if (prmHeadNode == NULL)
		return (NULL);

	new = _createEnvNode(prngbl);
	if (new == NULL)
		return (NULL);

	if (*prmHeadNode == NULL)
		*prmHeadNode = new;
	else
	{
		last = _getLastEnvNode(*prmHeadNode);
		if (last == NULL)
		{
			free(new);
			return (NULL);
		}
		last->next = new;
	}

	return (new);
}
