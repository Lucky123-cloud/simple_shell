#include "shell.h"
/**
 * _exits - for exiting the shell
 * @prnd: prints data
 * Return: void
 */
void _exits(appData_t *prnd)
{
	int a = EXIT_SUCCESS;

	if (prnd == NULL)
		return;
	if (prnd->arguments != NULL)
	{
		a = _atoi(prnd->arguments[1]);
	}
	if (a < 0 || (prnd->arguments[1] != NULL && !_isNumber(prnd->arguments[1])))
	{
		_ErrorHandling(prnd, 106);
		a = 2;
	}
	_Freeappdata(prnd);
	_FreeEnvironList(prnd->env);
	prnd->env = NULL;
	free(prnd);
	exit(a);
}
