#include "shell.h"

/**
 * _getLastEnvNode - This is used to get the last node
 *
 * @prnHeadNode: This is the first node
 *
 * Return: returns this as the last element
 */
environment_t *_getLastEnvNode(environment_t *prnHeadNode)
{
	environment_t *head, *next;

	head = prnHeadNode;

	if (head == NULL)
		return (NULL);

	next = head->next;

	if (next == NULL)
		return (head);
	else
		return (_getLastEnvNode(next));
}
