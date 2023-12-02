#include "shell.h"

/**
 * _Freeappdata - tries to free all pointers of the application
 *
 * @prndata:  main data structure of this function
 */
void _Freeappdata(appData_t *prndata)
{
	if (prndata == NULL)
		return;

	if (prndata->arguments != NULL)
		_freeCharDoublePointer(prndata->arguments);
	prndata->arguments = NULL;
	if (prndata->buffer != NULL)
		free(prndata->buffer);
	prndata->buffer = NULL;
	if (prndata->commandName != NULL)
		free(prndata->commandName);
	prndata->commandName = NULL;
	if (prndata->commandList != NULL)
		_freeCharDoublePointer(prndata->commandList);
	prndata->commandList = NULL;
	if (prndata->history != NULL)
		_freeCharDoublePointer(prndata->history);
	prndata->history = NULL;
}
