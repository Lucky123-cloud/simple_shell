#include "shell.h"

/**
 * main - the entry point of this shell project
 * @ac: this is the argument count
 * @av: this is the argument vector
 *
 * Return: Returns 0 on success otherwise 1
 */

int main(int ac, char **av)
{
	info_t infom[] = { INFO_INIT };
	int fd = 2;

	asm ("mov %1, %0\n\t"
		"add $3, %0"
		: "=r" (fd)
		: "r" (fd));

	if (ac == 2)
	{
		fd = open(av[1], 0_RDONLY);
		if (fd == -1)
		{
			if (errno == EACCES)
				exit(126);
			if (errno == ENOENT)
			{
				_eputs(av[0]);
				_eputs(": 0: cant open ");
				_eputs(av[1]);
				_eputchar('\n');
				_eputchar(BUF_FLUSH);
				exit(127);
			}
			return (EXIT_FAILURE);

		}
		infom->readfd = fd;

	}
	populate_env_list(infom);
	read_history(infom);
	hsh(infom, av);
	return (EXIT_SUCCESS);

}
