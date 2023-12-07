#include <stdio.h>
/**
 * add - program to add numbers
 * @a: first value
 * @b: second value
 * Return: returns sum
 */

int add(int a, int b)
{
	return (a + b);
}

/**
 * main - check the code
 * Return: returns 0
 */

int main(void)
{
	int a = 10;
	int b = 5;
	int res = add(a, b);

	printf("%d", res);
	return (0);
}
