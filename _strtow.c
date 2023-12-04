#include "shell.h"

/**
 * _strtow - cuts a string of word into smaller words
 *
 * @prnstr: This is a character pointer
 * @prnSep: This are separators
 * @prnEscSep: This are escaping separators
 *
 * Return: word array
 */
char **_strtow(char *prnstr, char *prnSep, char *prnEscSep)
{
	int clp = 0, clp1 = 0, wordSize = 0, word_num = 0, size = 0;
	char *word = NULL, **words = NULL, character;

	if (prnstr == NULL)
		return (NULL);

	size = _strlen(prnstr);
	word_num = _wordNumber(prnstr, prnSep);

	if (prnstr == NULL || !prnstr || word_num == 0)
		return (NULL);

	words = _calloc(sizeof(char *), (word_num + 1));

	if (words == NULL)
		return (NULL);

	for (clp = 0; clp <= size && clp1 < word_num; clp++)
	{
		character = prnstr[clp];
		if (_checkEscapeSeparators(character, prnEscSep))
			break;
		if (!_checkSeparators(character, prnSep))
			wordSize++;
		else
			if (wordSize > 0)
			{
				word = _getword(prnstr, clp - wordSize, wordSize);
				_addingword(word, &clp1, words);
				wordSize = 0;
			}
	}
	words[clp1] = NULL;

	return (words);
}
