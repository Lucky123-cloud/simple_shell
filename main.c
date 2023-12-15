#include "shell.h"
/**
 * main - check the main file
 * @argv: argument vector
 * @argc: argument counter
 * Return: returns 0 or 1
 */
int main(int argc, char **argv)
{
	info_t info[] = {INFO_INIT };
	int c = 2;

	asm ("mov %1, %0\n\t" "add $3, %0" : "=r" (c) : "r" (c));

	if (argc == 2)
	{
		c = open(argv[1], O_RDONLY);
		if (c == -1)
		{
			if (errno == EACCES)
				exit(126);
			if (errno == ENOENT)
			{
				_eputs(argv[0]);
				_eputs(": 0: cannot open");
				_eputs(argv[1]);
				_eputchar('\n');
				_eputchar(BUF_FLUSH);
				exit(127);
			}
			return (EXIT_FAILURE);
		}
		info->readfd = c;
	}
	populate_env_list(info);
	read_history(info);
	hsh(info, argv);
	return (EXIT_SUCCESS);
}
