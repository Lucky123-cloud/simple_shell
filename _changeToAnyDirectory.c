#include "shell.h"

/**
 * _changeToAnyDirectory - This helps in changing to any directory
 *
 * @prnd: This is how is stored,data structure
 * @prnCurrentDir: current directory path
 */
void _changeToAnyDirectory(appData_t *prnd, char *prnCurrentDir)
{
	char *newDir;

	newDir = prnd->arguments[1];

	if (access(newDir, R_OK | W_OK) == 0)
	{
		chdir(newDir);
		/* set old path environment variable */
		_setenv_val(prnd->env, "OLDPWD", prnCurrentDir, 1);
	}
	else
		perror(newDir);
}
