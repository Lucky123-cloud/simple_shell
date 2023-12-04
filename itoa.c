#include "shell.h"
/**
 * _itoa - converts integer to string
 * @num: displays value to convert
 * Return: returns string
 */
char *_itoa(int num)
{
char *a;
int loop;
long n;

n = num;
loop = _nbrLen(n);
a = malloc(sizeof(char) * loop + 1);

if (a == NULL)
{
	return (NULL);
}
a[loop] = '\0';

if (n == 0)
{
	a = "0";
}
else if (n < 0)
{
	a[0] = '-';
	n *= -1;
}

while (n)
{
	a[-- loop] = n % 10 + 48;
	n /= 10;
}
return (a);
}
