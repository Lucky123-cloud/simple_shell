#include "shell.h"

/**
 * _execCommand - This is an Executing command
 * @prnd: This is an app data array
 */
void _execCommand(appData_t *prnd)
{
	pid_t child_pid;
	char *command;
	int status;

	if (prnd->commandName == NULL)
		return;

	/* Get the absolute path of the command */
	command = _whichpath(prnd);

	if (command != NULL)
	{
		if (prnd->commandName != command)
			free(prnd->commandName);
		prnd->commandName = command;
	}
	else
	{
		return;
	}

	/* Create a child */
	child_pid = fork();
	if (child_pid == 0)
	{
		/* Execute command*/
		if (execve(prnd->commandName, prnd->arguments, NULL) == -1)
			_ErrorHandling(prnd, 103);
		return;
	}
	else if (child_pid == -1)
	{
		_ErrorHandling(prnd, 102);
	}
	else
		waitpid(child_pid, &status, WUNTRACED);
}
