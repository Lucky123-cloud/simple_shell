#include "shell.h"
/**
 * _atoi - string to integer
 * @prnstr: prints character
 * Return: returns integer
 */
int _atoi(char *prnstr)
{
	char a = 1, now;
	int sizes = _strlen(prnstr), loop;
	unsigned int c = 0;

	for (loop = 0; loop < sizes; loop++;
	{
		now = prnstr[loop];

		if (_isdigit(now))
		{
			c *= 10;
			c += now - 48;
		}
		else if (now == '-')
			a = -sign;
		else if (c > 0)
			break;
	}
	return (a * c);
}
