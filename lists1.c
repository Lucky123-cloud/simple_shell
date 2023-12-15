#include "shell.h"

/**
 * list_len - checks the length of the list 
 * @a: check the parameter
 * Return: returns value of the list
 */
size_t list_len(const list_t *a)
{
	size_t b = 0;

	while (a)
	{
		a = a->next;
		b++;
	}
	return (b);
}

/**
 * list_to_strings - checks the list of strings
 * @hd: this is the first parameter node
 * Return: returns value
 */
char **list_to_strings(list_t *hd)
{
	list_t *n = hd;
	size_t a = list_len(hd), b;
	char **st;
	char *g;

	if (!hd || !a)
		return (NULL);
	st = malloc(sizeof(char *) * (a + 1));
	if (!st)
		return (NULL);
	for (a = 0; n; n = n->next, a++)
	{
		g = malloc(_strlen(n->str) + 1);

		if (!g)
		{
			for (b = 0; b < a; b++)
				free(st[b]);
			free(g);
			return (NULL);
		}

		g = _strcpy(g, n->str);
		st[a] = g;
	}
	st[a] = NULL;
	return (st);
}


/**
 * print_list - prints a list
 * @hd: this is the first node parameter
 * Return: returns value
 */
size_t print_list(const list_t *hd)
{
	size_t a = 0;

	while (hd)
	{
		_puts(convert_number(hd->num, 10, 0));
		_putchar(':');
		_putchar(' ');
		_puts(hd->str ? hd->str : "(nil)");
		_puts("\n");
		hd = hd->next;
		a++;
	}
	return (a);
}

/**
 * node_starts_with - checks the node
 * @n: value of node parameters
 * @p: starts the parameters
 * @k: checks the next parameters
 * Return: returns 1 or 0
 */
list_t *node_starts_with(list_t *n, char *p, char k)
{
	char *a = NULL;

	while (n)
	{
		a = starts_with(n->str, p);
		if (a && ((k == -1) || (*a == k)))
			return (n);
		n = n->next;
	}
	return (NULL);
}

/**
 * get_node_index - checks the index of the nose
 * @hd: checks the first parameter
 * @n: checks the next code
 * Return: returns value
 */
ssize_t get_node_index(list_t *hd, list_t *n)
{
	size_t a = 0;

	while (hd)
	{
		if (hd == n)
			return (a);
		hd = hd->next;
		a++;
	}
	return (-1);
}
