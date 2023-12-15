#include "shell.h"

/**
 * _myenv - checks the environment
 * @adr: gives us address parameter
 * Return: Always 0
 */
int _myenv(info_t *adr)
{
	print_list_str(adr->env);
	return (0);
}

/**
 * _getenv - environment variable
 * @adr: checks the parameter structure
 * @b: parameter character
 * Return: returns null
 */
char *_getenv(info_t *adr, const char *b)
{
	list_t *node = adr->env;
	char *k;

	while (node)
	{
		k = starts_with(node->str, b);
		if (k && *k)
			return (k);
		node = node->next;
	}
	return (NULL);
}

/**
 * _mysetenv - sets environment
 * @adr: checks the parameter 1
 *  Return: returns 0
 */
int _mysetenv(info_t *adr)
{
	if (adr->argc != 3)
	{
		_eputs("Incorrect number of arguements\n");
		return (1);
	}
	if (_setenv(adr, adr->argv[1], adr->argv[2]))
		return (0);
	return (1);
}

/**
 * _myunsetenv - unset environment variable
 * @adr: address of the parameter
 * Return: returns 0
 */
int _myunsetenv(info_t *adr)
{
	int a;

	if (adr->argc == 1)
	{
		_eputs("Too few arguements.\n");
		return (1);
	}
	for (a = 1; a <= adr->argc; a++)
		_unsetenv(adr, adr->argv[a]);

	return (0);
}

/**
 * populate_env_list - gives us linked list
 * @adr: structure parsmeter
 * Return: returns 0
 */
int populate_env_list(info_t *adr)
{
	list_t *node = NULL;
	size_t l;

	for (l = 0; environ[l]; l++)
		add_node_end(&node, environ[l], 0);
	adr->env = node;
	return (0);
}
