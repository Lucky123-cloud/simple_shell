#include "shell.h"

/**
 * _help - help in making all the command help functions
 *
 * @prnd: This is data structure that helps in making func
 */
void _help(appData_t *prnd)
{
	if (prnd == NULL)
		return;
	if (prnd->commandName == NULL)
		return;
	if (
		prnd->arguments == NULL ||
		prnd->arguments[0] == NULL ||
		prnd->arguments[1] == NULL
	)
		return;
	if (_strcmp(prnd->arguments[1], "cd") == 0)
		_cdHelp();
	else if (_strcmp(prnd->arguments[1], "env") == 0)
		_envHelp();
	else if (_strcmp(prnd->arguments[1], "setenv") == 0)
		_setenvHelp();
	else if (_strcmp(prnd->arguments[1], "unsetenv") == 0)
		_unsetenvHelp();
	else if (_strcmp(prnd->arguments[1], "exit") == 0)
		_exitHelp();
	else if (_strcmp(prnd->arguments[1], "help") == 0)
		_helpHelp();
	else
		_defaultHelp(prnd->arguments[1]);
}
