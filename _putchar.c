#include "shell.h"

/**
 * _putchar - writes character to the standrad output console
 *
 * @prnchar: character to be printed on the console as stdout
 *
 * Return: returns the number of printed characters
 */

int _putchar(char prnchar)
{
	return (write(STDIN_FILENO, &prnchar, sizeof(int)));
}

