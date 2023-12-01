#include "shell.h"

/**
 * hsh - This is the main shell loop of this project
 * @infom: the parameter & return infom struct from the process
 * @av: the argument vector from main() function
 *
 * Return: Always 0 on success, 1 on error otherwise an or error code
 */
int hsh(info_t *infom, char **av)
{
	ssize_t s = 0;
	int builtin_ret = 0;

	while (s != -1 && builtin_ret != -2)
	{
		clear_info(info);
		if (interactive(info))
			_puts("$ ");
		_eputchar(BUF_FLUSH);
		s = get_input(info);
		if (s != -1)
		{
			set_info(info, av);
			builtin_ret = find_builtin(info);
			if (builtin_ret == -1)
				find_cmd(info);
		}
		else if (interactive(info))
			_putchar('\n');
		free_info(info, 0);
	}
	write_history(info);
	free_info(info, 1);
	if (!interactive(info) && info->status)
		exit(info->status);
	if (builtin_ret == -2)
	{
		if (info->err_num == -1)
			exit(info->status);
		exit(info->err_num);
	}
	return (builtin_ret);
}

/**
 * find_builtin - tries to find a builtin command in users input or program
 * @infom: the parameter & return infomation struct
 *
 * Return: -1 if builtin not found and then;
 *			0 if builtin executed successfully,
 *			1 if builtin found but not successful,
 *			-2 if builtin signals exit()
 */
int find_builtin(info_t *infom)
{
	int i, built_in_ret = -1;
	builtin_table builtintbl[] = {
		{"exit", _myexit},
		{"env", _myenv},
		{"help", _myhelp},
		{"history", _myhistory},
		{"setenv", _mysetenv},
		{"unsetenv", _myunsetenv},
		{"cd", _mycd},
		{"alias", _myalias},
		{NULL, NULL}};

	for (i = 0; builtintbl[i].type; i++)
		if (_strcmp(info->argv[0], builtintbl[i].type) == 0)
		{
			infom->line_count++;
			built_in_ret = builtintbl[i].func(infom);
			break;
		}
	return (built_in_ret);
}

/**
 * find_cmd - tries to find a command in PATH that is not identified
 * @infom: the parameter & return information of the struct struct
 *
 * Return: should return nothing in particular (void)
 */
void find_cmd(info_t *infom)
{
	char *path = NULL;
	int j, m;

	info->path = infom->argv[0];
	if (infom->linecount_flag == 1)
	{
		infom->line_count++;
		infom->linecount_flag = 0;
	}
	for (j = 0, m = 0; infom->arg[j]; j++)
		if (!is_delim(infom->arg[j], " \t\n"))
			m++;
	if (!m)
		return;

	path = find_path(infom, _getenv(infom, "PATH="), infom->argv[0]);
	if (path)
	{
		infom->path = path;
		fork_cmd(infom);
	}
	else
	{
		if ((interactive(infom) || _getenv(infom, "PATH=") || infom->argv[0][0] == '/') && is_cmd(infom, infom->argv[0]))
			fork_cmd(infom);
		else if (*(infom->arg) != '\n')
		{
			infom->status = 127;
			print_error(infom, "not found\n");
		}
	}
}

/**
 * fork_cmd - produces an exec thread to run cmd commands individually
 * @info: the  main parameter and it return information about the struct
 *
 * Return: should return nothing in particular (void)
 */

/**
 * Fork system call is used for creating a new process, which is called child process,
 *  which runs concurrently with the process that makes the fork() call (parent process).
 *  After a new child process is created,
 * both processes will execute the next instruction following the fork() system call.
 *  A child process uses the same pc(program counter),
 * same CPU registers, same open files which use in the parent process.
 */
void fork_cmd(info_t *infom)
{
	pid_t child_pid;

	child_pid = fork();
	if (child_pid == -1)
	{
		/* TODO: PUT ERROR FUNCTION */
		perror("Error:");
		return;
	}
	if (child_pid == 0)
	{
		if (execve(infom->path, infom->argv, get_environ(infom)) == -1)
		{
			free_infom(infom, 1);
			if (errno == EACCES)
				exit(126);
			exit(1);
		}
		/* TODO: PUT ERROR FUNCTION */
	}
	else
	{
		wait(&(infom->status));
		if (WIFEXITED(infom->status))
		{
			infom->status = WEXITSTATUS(infom->status);
			if (infom->status == 126)
				print_error(infom, "Permission denied\n");
		}
	}
}
