#include "shell.h"
/**
 * main - This is the main function of the programme
 *
 * Return: always 0 on success
 */
int main(int argc __attribute__((unused)), char **argv)
{
	appData_t *appData = NULL;
	int clp;
	void (*func)(appData_t *);
	appData = _initData(argv);
	
	do
	{
		signal(SIGINT, _ctrlD);
		_prompt();
		_getline(appData);
		appData->history = _strtow(appData->buffer, COMMAND_SEPARATOR, ESCAPE_SEPARATOR);

		if (appData->history == NULL)
		{
			_Freeappdata(appData);
			free(appData);
			continue;
		}
		for (clp = 0; appData->history[clp] != NULL; clp++)
		{
			appData->arguments = _strtow(appData->history[clp], SEPARATORS, ESCAPE_SEPARATOR);

			if (appData->arguments == NULL)
			{
				_Freeappdata(appData);
				_FreeEnvironList(appData->env);
				appData->env = NULL;
				free(appData);
				appData = NULL;
				break;
			}
			appData->commandName = _strdup(appData->arguments[0]);

			if (appData->commandName != NULL)
			{
				func = _getcustomfunc(appData->commandName);

				if (func != NULL)
					func(appData);
				else
					_execCommand(appData);
			}
			_freeCharDoublePointer(appData->arguments);
			appData->arguments = NULL;
			free(appData->commandName);
			appData->commandName = NULL;
		}
		_Freeappdata(appData);
	}
	while (1);
		return (EXIT_SUCCESS);

	{
		int a = 10;
		int b = 5;
		int res;

		res = add(a, b);
		printf("%d", res);
		return (0);
	}
}
