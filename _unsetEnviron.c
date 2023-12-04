#include "shell.h"

/**
 * _unsetEnviron - function that helps in unsetting environment variable
 *
 * @prndata: This is how the data is stored in the memory(data ststructure)
 */
void _unsetEnviron(appData_t *prndata)
{
	if (prndata == NULL)
		return;

	if (prndata->arguments == NULL)
		return;

	if (prndata->arguments[1] == NULL)
		return;

	_unsetenv(prndata, prndata->arguments[1]);
}
