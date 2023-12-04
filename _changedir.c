#include "shell.h"

/**
 * _cd - change current directory
 *
 * @prnd: Print data structure
 */
void _cd(appData_t *prnd)
{
	char currentDirectory[500];

	getcwd(currentDirectory, 500);

	if (prnd == NULL)
		return;

	if (
		!prnd->arguments[1] ||
		_strcmp(prnd->arguments[1], "~") == 0 ||
		_strcmp(prnd->arguments[1], "~/") == 0
	)
		_changeToHomeDirectory(prnd, currentDirectory);
	/* Old path */
	else if (_strcmp(prnd->arguments[1], "-") == 0)
		_changeToPreviousDirectory(prnd, currentDirectory);
	else
		_changeToAnyDirectory(prnd, currentDirectory);
}
