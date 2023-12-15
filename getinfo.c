#include "shell.h"

/**
 * clear_info - clears information
 * @adr: checks the address
 */
void clear_info(info_t *adr)
{
	adr->arg = NULL;
	adr->argv = NULL;
	adr->path = NULL;
	adr->argc = 0;
}

/**
 * set_info - sets the information
 * @adr: checks the address
 * @av: checks argument vector
 */
void set_info(info_t *adr, char **av)
{
	int a = 0;

	adr->fname = av[0];
	if (adr->arg)
	{
		adr->argv = strtow(adr->arg, " \t");
		if (!adr->argv)
		{

			adr->argv = malloc(sizeof(char *) * 2);
			if (adr->argv)
			{
				adr->argv[0] = _strdup(adr->arg);
				adr->argv[1] = NULL;
			}
		}
		for (a = 0; adr->argv && adr->argv[a]; a++)
			;
		adr->argc = a;

		replace_alias(adr);
		replace_vars(adr);
	}
}

/**
 * free_info - free information
 * @adr: checks address parameter
 * @f: freeing parameter
 *
 */
void free_info(info_t *adr, int f)
{
	ffree(adr->argv);
	adr->argv = NULL;
	adr->path = NULL;
	if (f)
	{
		if (!adr->cmd_buf)
			free(adr->arg);
		if (adr->env)
			free_list(&(adr->env));
		if (adr->history)
			free_list(&(adr->history));
		if (adr->alias)
			free_list(&(adr->alias));
		ffree(adr->environ);
			adr->environ = NULL;
		bfree((void **)adr->cmd_buf);
		if (adr->readfd > 2)
			close(adr->readfd);
		_putchar(BUF_FLUSH);
	}
}
