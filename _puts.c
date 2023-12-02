#include "shell.h"

/**
 * _puts - write all char from string to stdout
 *
 * @prnstr: string to be printed on the stdout
 *
 * Return: The number of characters printed
 */

int _puts(char *prnstr)
{
	int i = 0, sum = 0;

	while (prnstr[i])
	{
		sum += _putchar(prnstr[i]);
		i++;
	}
	return (sum);
}

