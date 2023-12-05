#include "shell.h"
/**
 * _nbrLen - gives us the length of numbers
 * @num: prints a number
 * Return: returns value
 */
int _nbrLen(int num)
{
	int loop = 0;
	int n;

	if (num == 0)
		return (1);
	n = num;

	if (n < 0)
	{
		n *= -1;
		loop++;
	}
	while (n)
	{
		n /= 10;
		loop++;
	}
	return (loop);
}
