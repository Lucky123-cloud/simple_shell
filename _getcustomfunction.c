#include "shell.h"

/**
 * _getcustomfunc - check custom command
 *
 * @prnCommand: command
 *
 * Return: pointer function
 */
void (*_getcustomfunc(char *prnCommand))(appData_t *)
{
	int i = 0;

	customCommand_t fp[] = {
		{"cd", _cd},
		{"env", _env},
		{"setenv", _setEnvironment},
		{"unsetenv", _unsetEnviron},
		{"exit", _exits},
		{"help", _help}
	};

	while (i < 6)
	{
		if (_strcmp(prnCommand, (fp + i)->commandName) == 0)
			return ((fp + i)->func);
		i++;
	}

	return (NULL);
}
