#include "shell.h"

/**
 * main - this is the main code
 * @ac: checks the argument count
 * @av: checks argument vector
 * Return: 0 on success, 1 on failure
 */
int main(int ac, char **av)
{
	info_t adr[] = { INFO_INIT };
	int f = 2;

	asm ("mov %1, %0\n\t"
		"add $3, %0"
		: "=r" (f)
		: "r" (f));

	if (ac == 2)
	{
		f = open(av[1], O_RDONLY);
		if (f == -1)
		{
			if (errno == EACCES)
				exit(126);
			if (errno == ENOENT)
			{
				_eputs(av[0]);
				_eputs(": 0: Can't open ");
				_eputs(av[1]);
				_eputchar('\n');
				_eputchar(BUF_FLUSH);
				exit(127);
			}
			return (EXIT_FAILURE);
		}
		adr->readfd = f;
	}
	populate_env_list(adr);
	read_history(adr);
	hsh(adr, av);
	return (EXIT_SUCCESS);
}
