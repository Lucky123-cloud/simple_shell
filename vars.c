#include "shell.h"

/**
 * is_chain - checks the chain delim parameters
 * @adr: address parameter
 * @buffer: gives us the buffer address
 * @a: parameter string
 * Return: 1 or 0
 */
int is_chain(info_t *adr, char *buffer, size_t *a)
{
	size_t d = *a;

	if (buffer[d] == '|' && buffer[d + 1] == '|')
	{
		buffer[d] = 0;
		d++;
		adr->cmd_buf_type = CMD_OR;
	}
	else if (buffer[d] == '&' && buffer[d + 1] == '&')
	{
		buffer[d] = 0;
		d++;
		adr->cmd_buf_type = CMD_AND;
	}
	else if (buffer[d] == ';')
	{
		buffer[d] = 0;
		adr->cmd_buf_type = CMD_CHAIN;
	}
	else
		return (0);
	*a = d;
	return (1);
}

/**
 * check_chain - checks the status of the chain
 * @adr: gives us the address parameter
 * @buffer: checks the character buffer
 * @a: check the buffer parameter1
 * @m: check the buffer parameter2
 * @lgth: checks the lengh
 * Return: returns void
 */
void check_chain(info_t *adr, char *buffer, size_t *a, size_t m, size_t lgth)
{
	size_t d = *a;

	if (adr->cmd_buf_type == CMD_AND)
	{
		if (adr->status)
		{
			buffer[m] = 0;
			d = lgth;
		}
	}
	if (adr->cmd_buf_type == CMD_OR)
	{
		if (!adr->status)
		{
			buffer[m] = 0;
			d = lgth;
		}
	}

	*a = d;
}

/**
 * replace_alias - replace string alias
 * @adr: address parameter
 * Return: returns 1 or 0
 */
int replace_alias(info_t *adr)
{
	int a;
	list_t *n;
	char *c;

	for (a = 0; a < 10; a++)
	{
		n = node_starts_with(adr->alias, adr->argv[0], '=');
		
		if (!n)
			return (0);
		free(adr->argv[0]);
		c = _strchr(n->str, '=');
		
		if (!c)
			return (0);
		c = _strdup(c + 1);

		if (!c)
			return (0);
		adr->argv[0] = c;
	}
	return (1);
}

/**
 * replace_vars - replace var
 * @adr: address parameter
 * Return: 1 if replaced otherwise 0
 */
int replace_vars(info_t *adr)
{
	int a = 0;
	list_t *n;

	for (a = 0; adr->argv[a]; a++)
	{
		if (adr->argv[a][0] != '$' || !adr->argv[a][1])
			continue;

		if (!_strcmp(adr->argv[a], "$?"))
		{
			replace_string(&(adr->argv[a]),	_strdup(convert_number(adr->status, 10, 0)));
			continue;
		}
		if (!_strcmp(adr->argv[a], "$$"))
		{
			replace_string(&(adr->argv[a]),
				_strdup(convert_number(getpid(), 10, 0)));
			continue;
		}
		n = node_starts_with(adr->env, &adr->argv[a][1], '=');
		if (n)
		{
			replace_string(&(adr->argv[a]),
				_strdup(_strchr(n->str, '=') + 1));
			continue;
		}
		replace_string(&adr->argv[a], _strdup(""));

	}
	return (0);
}

/**
 * replace_string - replace the string parameter
 * @a: value of old strin
 * @aa: value of current string
 * Return: returns 1 otherwise 0
 */
int replace_string(char **a, char *aa)
{
	free(*a);
	*a = aa;
	return (1);
}
