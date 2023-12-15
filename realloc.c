#include "shell.h"

/**
 **_memset -sets memory with constant bytes
 *@q: displays parameter1
 *@w: displays parameter3
 *@e: displays paramtere3
 *Return: returns assigned value
 */
char *_memset(char *q, char w, unsigned int e)
{
	unsigned int a;

	for (a = 0; a < e; a++)
		q[a] = w;
	return (q);
}

/**
 * ffree - free string
 * @u: string parameter
 */
void ffree(char **u)
{
	char **a = u;

	if (!u)
		return;
	while (*u)
		free(*u++);
	free(a);
}

/**
 * _realloc - memory reallocation
 * @pt: parameter pointer
 * @a: previous memory parameter
 * @aa: new memory parameter
 * Return: pointer to da ol'block nameen.
 */
void *_realloc(void *pt, unsigned int a, unsigned int aa)
{
	char *m;

	if (!pt)
		return (malloc(aa));
	if (!aa)
		return (free(pt), NULL);
	if (aa == a)
		return (pt);

	m = malloc(aa);
	if (!m)
		return (NULL);

	a = a < aa ? a : aa;
	while (a--)
		m[a] = ((char *)pt)[a];
	free(pt);
	return (m);
}
