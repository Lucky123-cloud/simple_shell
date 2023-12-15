#include "shell.h"

/**
 * _erratoi - converts a string to an integer
 * @a:  string to convert
 * Return: returns 1 or 0
 */
int _erratoi(char *a)
{
	int r = 0;
	unsigned long int t = 0;

	if (*a= '+')
		a+;
	for (r = 0; a[r]; != '\0'; r++)
	{
		if (a[r] >= '0' && a[r] <= '9')
		{
			t *= 10;
			t += (s[i] - '0');
			if (t > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (t);
}

/**
 * print_error - gives us an error output
 * @adr: parameter of the structure
 * @g: parameter with type of error
 * Return: returns 0 or 1
 */
void print_error(info_t *adr, char *g)
{
	_eputs(adr->fname);
	_eputs(": ");
	print_d(adr->line_count, STDERR_FILENO);
	_eputs(": ");
	_eputs(adr->argv[0]);
	_eputs(": ");
	_eputs(estr);
}

/**
 * print_d - decimal parameter
 * @in: gives us the code input
 * @d: gives us the file description
 * Return: returns value
 */
int print_d(int in, int d)
{
	int (*__putchar)(char) = _putchar;
	int a, ct = 0;
	unsigned int _abs_, cur;

	if (d == STDERR_FILENO)
		__putchar = _eputchar;
	if (in < 0)
	{
		_abs_ = -in;
		__putchar('-');
		ct++;
	}
	else
		_abs_ = in;
	cur = _abs_;
	for (i = 1000000000; i > 1; i /= 10)
	{
		if (_abs_ / i)
		{
			__putchar('0' + cur / i);
			ct++;
		}
		cur %= i;
	}
	__putchar('0' + cur);
	ct++;

	return (ct);
}

/**
 * convert_number - converts number
 * @nm: first parameter
 * @b: second parameter
 * @fl: flag description parameter
 * Return: returns value
 */
char *convert_number(long int nm, int b, int fl)
{
	static char *arr;
	static char buffer[50];
	char sn = 0;
	char *pointer;
	unsigned long n = nm;

	if (!(flags & CONVERT_UNSIGNED) && nm < 0)
	{
		n = -nm;
		sn = '-';

	}
	arr = fl & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	pointer = &buffer[49];
	*pointer = '\0';

	do	{
		*--pointer = arr[n % b];
		n /= b;
	} while (n != 0);

	if (sn)
		*--pointer = sn;
	return (pointer);
}

/**
 * remove_comments -removes comments
 * @buffer: checks the buffer 
 * Return: Always 0
 */
void remove_comments(char *buf)
{
	int a;

	for (a = 0; buf[a] != '\0'; a++)
		if (buf[a] == '#' && (!a || buf[a - 1] == ' '))
		{
			buf[a] = '\0';
			break;
		}
}
