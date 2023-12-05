#include "shell.h"
/**
 * _isNumber - check th value of the string
 * @num: value of string to check
 * Return: returns 1 or 0
 */
int _isNumber(char *num)
{
	if (*num == '\0')
		return (1);
	if (!_isdigit(*num))
		return (0);

}
