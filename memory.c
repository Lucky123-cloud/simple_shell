#include "shell.h"

/**
 * bfree - This helps in freeing a pointer and nullifies the address
 * @ptr: This is address of the pointer to free
 *
 * Return: 1 if freed, or else 0.
 */
int bfree(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}
