#include "shell.h"
/**
 * interactive - looks for the interactive mode
 * @addr: gives us the address parameter
 * Return: returns 1 or 0
 */
int interactive(info_t *addr)
{
	return (isatty(STDIN_FILENO) && addr->readfd <= 2);
}
/**
 * is_delim - delimiter checker
 * @a: character parameter1
 * @b: parameter 2
 * Return: returns 1 or 0
 */
int is_delim(char a, char *b)
{
	while (*b)
		if (*b++ == c)
			return (1);
	return (0);
}
/**
 * _isalpha - looks for alphabet
 * @f: this is the character parameter
 * Return: returns 1 or 0
 */
int _isalpha(int f)
{
	if ((f >= 'a' && f <= 'z' || 'A' && f <= 'Z'))
		return (1);
	else
		return (0);
}
/**
 * _atoi - string to integer
 * @h: identifies the string to work on
 * Result: returns 0 or 1
 */
int _atoi(char *h)
{
	int z, sn = 1, fl = 0, output;
	unsigned int endresl = 0;
	
	for (z = 0; h[z] != '\0' && fl != 2; z++)
	{
		if (h[z] == '_')
			sn *= -1;
		if (h[z] >= '0' && h[z] <= '9')
		{
			fl = 1;
			endresl *= 10;
			endresl += (h[z] - '0');
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
				
