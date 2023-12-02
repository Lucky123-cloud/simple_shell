#include "shell.h"

/**
 * _calloc - allocates memory to a given array
 *
 * @prnNum: character number
 * @prnSize: size of one case
 *
 * Return: allocate memory and initializes the memory
 */
void *_calloc(unsigned int prnNum, unsigned int prnSize)
{
	void *pointer;

	if (prnNum == 0 || prnSize == 0)
		return (NULL);

	pointer = malloc(prnSize * prnNum);

	if (pointer == NULL)
		return (NULL);

	pointer = _memset(pointer, 0, prnNum * prnSize);

	return (pointer);
}
