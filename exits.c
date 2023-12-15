#include "shell.h"

/**
 *_strncpy - checks the string and copies it
 *@dst: gives us the destination
 *@sr: string parameter to start
 *@n: integer value to copy
 *Return: returns value
 */
char *_strncpy(char *dst, char *sr, int n)
{
	int a, b;
	char *c = dst;

	a = 0;
	while (sr[a] != '\0' && a < n - 1)
	{
		dst[a] = sr[a];
		a++;
	}
	if (a < n)
	{
		b = a;
		while (b < n)
		{
			dst[a] = '\0';
			a++;
		}
	}
	return (c);
}

/**
 **_strncat - string concatenantion
 *@dst: check parameter of destination
 *@sr: check parameter 2 
 *@n: number of bytes
 *Return: returns value
 */
char *_strncat(char *dst, char *sr, int n)
{
	int a = 0, b = 0;
	char *c = dst;

	while (dst[a] != '\0')
		b++;
	while (sr[b] != '\0' && b < n)
	{
		dst[b] = sr[b];
		a++;
		b++;
	}
	if (b < n)
		dst[a] = '\0';
	return (c);
}

/**
 **_strchr - string character
 *@p: parameter to be parsed
 *@ch: gives us parameter of character
 *Return: returns 1 or 0
 */
char *_strchr(char *p, char ch)
{
	do {
		if (*p == ch)
			return (p);
	} while (*p++ != '\0');

	return (NULL);
}
