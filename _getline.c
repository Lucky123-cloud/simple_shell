#include "shell.h"

/**
 * _getline - Collect data from users andReturn command line type by user
 *
 * @prndata: data structure for informative purporses
 *
 * Return: buffer where the command is stored from the user
 */
void _getline(appData_t *prndata)
{
	char c = '\0';
	int j = 0, rd, bufferSize = BUFFER_SIZE;

	prndata->buffer = _calloc(sizeof(char), BUFFER_SIZE);

	while (c != '\n' && c != EOF)
	{
		rd = read(STDIN_FILENO, &c, 1);

		if (rd == 0)
		{
			_putchar('\n');
			if (prndata->env != NULL)
				_FreeEnvironList(prndata->env);
			prndata->env = NULL;
			_Freeappdata(prndata);
			free(prndata);
			exit(EXIT_SUCCESS);
		}

		if (j >= bufferSize - 1)
		{
			prndata->buffer = _realloc(
				prndata->buffer,
				bufferSize,
				sizeof(char) * (j + 2)
			);
			bufferSize = j + 2;
		}
		prndata->buffer[j] = c;
		j++;
	}
	prndata->buffer[j] = '\0';
}
