#include "shell.h"

/**
 * get_environ -gives us copy of the environ 
 * @adr: checks the function parameter
 * Return: returns 0
 */
char **get_environ(info_t *adr)
{
	if (!adr->environ || adr->env_changed)
	{
		adr->environ = list_to_strings(adr->env);
		adr->env_changed = 0;
	}

	return (adr->environ);
}

/**
 * _unsetenv - unset environment variable
 * @adr: checks the function parameter
 * @vr: checks the function parameter2
 *  Return: returns 1 or 0
 */
int _unsetenv(info_t *adr, char *vr)
{
	list_t *node = adr->env;
	size_t a = 0;
	char *f;

	if (!node || !vr)
		return (0);

	while (node)
	{
		f = starts_with(node->str, vr);
		if (f && *f == '=')
		{
			adr->env_changed = delete_node_at_index(&(adr->env), a);
			a = 0;
			node = adr->env;
			continue;
		}
		node = node->next;
		a++;
	}
	return (adr->env_changed);
}

/**
 * _setenv - sets the environment variable
 * @adr: function parameter
 * @vr: variable parameter
 * @val: value of parameter 
 *  Return: returns 0
 */
int _setenv(info_t *adr, char *vr, char *val)
{
	char *buffer = NULL;
	list_t *node;
	char *y;

	if (!vr || !val)
		return (0);

	buffer = malloc(_strlen(vr) + _strlen(val) + 2);
	if (!buffer)
		return (1);
	_strcpy(buffer, vr);
	_strcat(buffer, "=");
	_strcat(buffer, val);
	node = adr->env;
	while (node)
	{
		y = starts_with(node->str, vr);

		if (y && *y == '=')
		{
			free(node->str);
			node->str = buffer;
			adr->env_changed = 1;
			return (0);
		}
		node = node->next;
	}
	add_node_end(&(adr->env), buffer, 0);
	free(buffer);
	adr->env_changed = 1;
	return (0);
}
