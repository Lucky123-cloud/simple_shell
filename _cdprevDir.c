#include "shell.h"

/**
 * _cdprevDir - cd to the prev or change to previous directory
 *
 * @prnd: This is the data structure to be stored
 * @prnCurrentDir: This is current directory path
 */
void _cdprevDir(appData_t *prnd, char *prnCurrentDir)
{
	environment_t *newDir;

	newDir = _getenv_var(prnd->env, "OLDPWD");

	if (access(newDir->value, R_OK | W_OK) == 0)
	{
		chdir(newDir->value);
		/* set old path environment variable */
		_setenv_val(prnd->env, "OLDPWD", prnCurrentDir, 1);
	}
	else
	{
		perror(newDir->value);
	}
}
