#include "shell.h"
/**
 * _memset - This is the main function of the code
 * @prnstr: pointer to a string
 * @prnchar: prints a character to a string
 * @lim: limits to  the number of bytes
 * Return: returns value
 */
char *_memset(char *prnstr, char prnchar, unsigned int lim)
{
	unsigned int loop;

	for (loop = 0; loop < lim; loop++)
	{
		prnstr[loop] = prnchar;
	}
	return (prnstr);
}
