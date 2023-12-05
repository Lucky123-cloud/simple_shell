#include "shell.h"

/**
 * _generateAbsolutePath - Generate an absolute path from environment variable
 *
 * @prnpath: prints path environment variable
 * @prnCommandName: command name
 *
 * Return: returns absolute path
 */
char *_generateAbsolutePath(char *prnpath, char *prnCommandName)
{
	char *tmp, *path, *absolutePath, lastCharacter;
	int pathValueSize;

	path = _strdup(prnpath);
	pathValueSize = _strlen(path);
	lastCharacter = path[pathValueSize - 1];

	if (lastCharacter != '/')
	{
		tmp = path;
		path = _strconcat(tmp, "/");
		free(tmp);
	}

	tmp = "";
	tmp = _strconcat(tmp, path);
	absolutePath = _strconcat(tmp, prnCommandName);
	free(tmp);
	free(path);

	return (absolutePath);
}
