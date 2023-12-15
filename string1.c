#include "shell.h"

/**
 * _strcpy -this copies the string
 * @z: end of the code
 * @a: source parameter
 * Return: returns value
 */
char *_strcpy(char *z, char *a)
{
	int y = 0;

	if (z == a || a == 0)
		return (z);
	while (a[y])
	{
		z[y] = a[y];
		y++;
	}
	z[y] = 0;
	return (z);
}

/**
 * _strdup - string duplication
 * @x: parameter to be duplicated
 * Return: returns value
 */
char *_strdup(const char *x)
{
	int lgh = 0;
	char *r;

	if (x == NULL)
		return (NULL);
	while (*x++)
		lgh++;
	r = malloc(sizeof(char) * (lgh + 1));
	if (!r)
		return (NULL);
	for (lgh++; lgh--;)
		r[lgh] = *--x;
	return (r);
}

/**
 *_puts - checks the input parameter
 *@a: gives us the value to input
 * Return: NULL
 */
void _puts(char *a)
{
	int t = 0;

	if (!a)
		return;
	while (a[t] != '\0')
	{
		_putchar(a[t]);
		t++;
	}
}

/**
 * _putchar - write the code
 * @g: parameter to write
 * Return: returns 1 or 0
 */
int _putchar(char g)
{
	static int a;
	static char buffer[WRITE_BUF_SIZE];

	if (g == BUF_FLUSH || a >= WRITE_BUF_SIZE)
	{
		write(1, buffer, a);
		a = 0;
	}
	if (g != BUF_FLUSH)
		buffer[a++] = g;
	return (1);
}
