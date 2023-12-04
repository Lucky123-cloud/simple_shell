#include "shell.h"

/**
 * _memcpy - It helps copy n bytes from memory area src to memory area dest
 *
 * @prndest: This is the pointer to memory area
 * @prnsrc: This pointer to src memory area
 * @prnlimit: The number of bytes to fill in
 *
 * Return: pointer to dest
 */
char *_memcpy(char *prndest, char *prnsrc, unsigned int prnlimit)
{
	unsigned int clp;

	for (clp = 0; clp < prnlimit; clp++)
	{
		prndest[clp] = prnsrc[clp];
	}

	return (prndest);
}
