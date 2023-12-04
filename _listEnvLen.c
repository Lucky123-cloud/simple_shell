#include "shell.h"

/**
 * _listEnvLen - The of the length of a linked list
 *
 * @prnHead:  The first node of the linked list
 *
 * Return: length of the linked list
 */
int _listEnvLen(environment_t *prnHead)
{
	if (prnHead == NULL)
		return (0);
	if (prnHead->next == NULL)
		return (1);
	else
		return (_listEnvLen(prnHead->next) + 1);
}
