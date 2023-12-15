#include "shell.h"

/**
 * interactive - brings us to the interactive mode
 * @addr: struct address
 * Return: return 0 or 1
 */
int interactive(info_t *addr)
{
	return (isatty(STDIN_FILENO) && addr->readfd <= 2);
}

/**
 * is_delim - delimiter
 * @a: character parameter
 * @b: delimiter of the string
 * Return: returns 1 or 0
 */
int is_delim(char a, char *b)
{
	while (*b)
		if (*b++ == a)
			return (1);
	return (0);
}

/**
 *_isalpha - checks for letters of the alphabet
 *@v: character parameter
 *Return: returns 1 or 0
 */

int _isalpha(int v)
{
	if ((v >= 'a' && v <= 'z') || (v >= 'A' && v <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 *_atoi - converts  string to integer
 *@f: the string to convert
 *Return: returns 1 or 0
 */

int _atoi(char *f)
{
	int p, sn = 1, fl = 0, output;
	unsigned int endresl = 0;

	for (f = 0;  f[p] != '\0' && fl != 2; f++)
	{
		if (f[p] == '-')
			sn *= -1;

		if (f[p] >= '0' && f[p] <= '9')
		{
			fl = 1;
			endresl *= 10;
			endresl += (f[p] - '0');
		}
		else if (fl == 1)
			fl = 2;
	}

	if (sn == -1)
		output = -endresl;
	else
		output = endresl;

	return (output);
}
