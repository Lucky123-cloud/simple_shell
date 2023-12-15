#include "shell.h"

/**
 * is_cmd - this is the command to execute
 * @adr: this is the address parameter
 * @pt: gives us the path parameter
 * Return: returns 1 or 0
 */
int is_cmd(info_t *adr, char *pt)
{
	struct stat s;

	(void)adr;
	if (!pt || stat(pt, &s))
		return (0);

	if (s.st_mode & S_IFREG)
	{
		return (1);
	}
	return (0);
}

/**
 * dup_chars - this is to duplicate characters
 * @ptstr: checks the path of the string
 * @a: this tells us which parameter will start
 * @z: this tells us which parameter will end with
 * Return: returns value
 */
char *dup_chars(char *ptstr, int a, int z)
{
	static char buffer[1024];
	int w = 0, e = 0;

	for (e = 0, w = a; w < z; w++)
		if (ptstr[w] != ':')
			buffer[e++] = ptstr[a];
	buffer[e] = 0;
	return (buffer);
}

/**
 * find_path - checks the path to follow
 * @adr: checks the address parameter
 * @pthstr: represents string path
 * @cdd: check the parameter
 * Return: returns value
 */
char *find_path(info_t *adr, char *pthstr, char *cdd)
{
	int a = 0, crr = 0;
	char *p;

	if (!pthstr)
		return (NULL);
	if ((_strlen(cdd) > 2) && starts_with(cdd, "./"))
	{
		if (is_cmd(adr, cdd))
			return (cdd);
	}
	while (1)
	{
		if (!pthstr[a] || pthstr[a] == ':')
		{
			p = dup_chars(pthstr, crr, a);
			if (!*p)
				_strcat(p, cdd);
			else
			{
				_strcat(p, "/");
				_strcat(p, cdd);
			}
			if (is_cmd(adr, p))
				return (p);
			if (!pthstr[a])
				break;
			crr = a;
		}
		a++;
	}
	return (NULL);
}
