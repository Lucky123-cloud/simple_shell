#include "shell.h"

/**
 * _puts - write all characters from string to stdout
 *
 * @prnstr: string to print from the user
 *
 * Return:  return the number of printed characters on the console
 */

int _puts(char *prnstr)
{
	int i = 0, sum = 0;

	while (prmStr[i])
	{
		sum += _putchar(prnstr[i]);
		i++;
	}
	return (sum);
}
