#include "shell.h"

/**
 * _initData - This is the init data structure
 * @prmArgv: pointer to argument vector
 *
 * Return: This is the data structure
 */
appData_t *_initData(char **prnArgv)
{
	appData_t *appData;

	appData = malloc(sizeof(appData_t) * 1);

	if (appData == NULL)
		return (NULL);

	appData->arguments = NULL;
	appData->buffer = NULL;
	appData->commandName = NULL;
	appData->commandList = NULL;
	appData->history = NULL;
	appData->env = NULL;
	appData->programName = (prnArgv[0] != NULL) ? prnArgv[0] : NULL;
	_initEnvData(appData);

	return (appData);
}
