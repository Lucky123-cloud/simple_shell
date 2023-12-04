#include "shell.h"

/**
 * _changeToHomeDirectory - Makes the shell to change to home directory
 *
 * @prnd: helps in changing to home directory
 * @prnCurrentDir: prints out current directory path
 */
void _changeToHomeDirectory(appData_t *prnd, char *prnCurrentDir)
{
	environment_t *newDir;

	newDir = _getenv_var(prnd->env, "HOME");

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
