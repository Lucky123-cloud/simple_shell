#include "shell.h"

/**
 * _FreeEnvironList - helps by freeing a struct linked list
 *
 * @prnHeadNode: The first argumnet and the first element
 *
 * Return: frees a list_t list from any other programme
 */
void _FreeEnvironList(environment_t *prnHeadNode)
{
	if (prnHeadNode == NULL)
		return;
	_FreeEnvironList(prnHeadNode->next);
	free(prnHeadNode->name);
	prnHeadNode->name = NULL;
	free(prnHeadNode->value);
	prnHeadNode->value = NULL;
	free(prnHeadNode->global);
	prnHeadNode->global = NULL;
	free(prnHeadNode);
}
