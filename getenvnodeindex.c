#include "shell.h"
/**
 * _getEnvNodeAtIndex - gets the node of a linked list
 * @prnfirst: gives us the first element of a list
 * @i: value of the element
 * Return: returns value
 */
environment_t *_getEnvNodeAtIndex(environment_t *prnfirst, unsigned int i)
{
	unsigned int loop = 0;

	while (prnfirst != NULL)
	{
		if (i == loop)
			return (prnfirst);
		prnfirst = prnfirst->next;
		loop++;
	}
	return (NULL);
}
