#include "shell.h"

/**
 * _strconcat - main function that concatenates two strings.
 *
 * @prnstr1: first character pointer to concatenate
 * @prnstr2: second character pointer to concatenate
 *
 * Return: returns character pointer that has been concatenated
 */
char *_strconcat(char *prnstr1, char *prnstr2)
{
	char *ptr;
	int clp1, clp2, size;

	if (prnstr1 == NULL)
		prnstr1 = "\0";

	if (prnstr2 == NULL)
		prnstr2 = "\0";

	size = _strlen(prnstr1) + _strlen(prnstr2);
	ptr = malloc(sizeof(char) * (size + 1));

	if (ptr == NULL)
		return (NULL);

	for (clp1 = 0; prnstr1[clp1]; clp1++)
		ptr[clp1] = prnstr1[clp1];

	for (clp2 = 0; prnstr2[clp2]; clp1++, clp2++)
		ptr[clp1] = prnstr2[clp2];

	ptr[clp1] = '\0';

	return (ptr);
}
