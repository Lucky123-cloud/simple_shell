#include "shell.h"

/**
 * _ErrorHandling - handles errors by displaying an error message
 *
 * @prndata: The parameter of this function
 * @messagecode: The error number that is to be displayed
 *
 *Return: returns nothing (void)
 */

void _ErrorHandling(appData_t *prndata, int messagecode)
{
	int i = 0;

	errorMessage_t error[] = {
		{00, "Error unknown"},
		{100, "Error reading from Prompt - zero tokens"},
		{101, "No Such File or Directory"},
		{102, "FATAL ERROR: Cannot Create Child Process"},
		{103, "command not found"},
		{104, "FATAL: Memory Full."},
		{105, "FATAL ERROR: Cannot Create a CMD file."},
		{106, "Invalid Number check again"},
		{999, ""} /*error array and condition is ended*/
	};

	_puts(prndata->programName);
	_puts(": ");
	_puts("1");
	_puts(": ");
	_puts(prndata->commandName);
	_puts(": ");
	while (i < 9)
	{
		if (messagecode == (errors + i)->code)
		{
			_puts((errors + i)->msg);
			_puts(": ");
			_puts(prndata->arguments[1]);
		}
		i++;
	}
	_puts("\n");
}

