#include "shell.h"

/**
 * _cleanstr - removes unnecesaarily put trailing white spaces
 *
 * @prnstr: Str input by the user and is to be cleaned
 *
 * Return: A clean string whitespace free is returned
 */
char *_cleanstr(char *prnstr)
{
	int cLoopStart = 0, cLoopEnd = 0, size = 0;
	char *str;

	if (prnstr == NULL)
		return (NULL);

	size = _strlen(prnstr);

	while (_inArray(prnstr[cLoopStart], " ") == 1)
		cLoopStart++;

	cLoopEnd = size - 1;
	while (_inArray(prnstr[cLoopEnd], " ") == 1)
		cLoopEnd--;
	cLoopEnd = size - 1 - cLoopEnd;

	str = _calloc(sizeof(char), size - cLoopStart - cLoopEnd + 1);
	_strncpy(str, (prnstr + cLoopStart), size - cLoopStart - cLoopEnd);
	str[size - cLoopStart - cLoopEnd] = '\0';

	/**prmString = *string;*/
	prnstr = _realloc(
		prnstr,
		size,
		sizeof(char) * (size - cLoopStart - cLoopEnd + 1)
	);
	_strcpy(prnstr, str);
	prnstr[size - cLoopStart - cLoopEnd] = '\0';
	free(str);
	return (prnstr);
}

