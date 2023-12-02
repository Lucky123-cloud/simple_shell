#include "shell.h"

/**
 * read_command - used to read what the user inputs as a command
 *
 * @command: The command that the user inputs
 * @size: The size of the inputs used by the user
 *
 * Return: It returns nothing (void)
 */

void read_command(char *command, size_t size)
{
	if (fgets(command, size, stdin) == NULL)
	{
		if (feof(stdin))
		{
			_putchar("\n");
			exit(EXIT_SUCCESS);
		} else
		{
			_putchar("Error while taking your input.\n");
			exit(EXIT_FAILURE);
		}
	}

	command[strcspn(command, "\n")] = '\0';
}
