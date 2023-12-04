#include "shell.h"
/**
 * _cd - changes directory
 * @prnd: structures the data
 * Return: returns void
 */
void _cd(appData_t *prnd)
{
char a[500];
getcwd(a, 500);

if (prnd == NULL)
	return;
if (!prnd->arguments[1] ||
	_strcmp(prnd->arguments[1], "~") == 0 ||
	_strcmp(prnd->arguments[1], "~/") == 0)
{
	_cd(prnd, a);

	else if (_strcmp(prnd->arguments[1], "-") == 0)
		_cd(prnd, a);
	else
		_cd(prnd, a);
}
}
