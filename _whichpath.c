#include "shell.h"

/**
 * _whichpath - helps in returning absolute path of a command
 *
 * @prnd: application data structure as stored in the mem
 *
 * Return: returns an absolute path
 */
char *_whichpath(appData_t *prnd)
{
	char **pathList, *absolutePath;
	struct stat st;
	int clp = 0;

	if (
		prnd->commandName[0] == '.' &&
		prnd->commandName[1] == '/' &&
		stat(prnd->commandName, &st) == 0
	)
		return (prnd->commandName);

	pathList = _parsingEnv(prnd);

	if (pathList == NULL)
		return (NULL);

	while (pathList[clp] != NULL)
	{
		absolutePath = _generateAbsolutePath(pathList[clp], prnd->commandName);

		/* Check if absolute path exist */
		if (stat(absolutePath, &st) == 0)
		{
			_freeCharDoublePointer(pathList);
			return (absolutePath);
		}
		free(absolutePath);
		clp++;
	}
	_freeCharDoublePointer(pathList);

	/* Try to find the command */
	if (stat(prnd->commandName, &st) == 0)
	{
		return (prnd->commandName);
	}
	else
		_ErrorHandling(prnd, 101);

	return (NULL);
}
