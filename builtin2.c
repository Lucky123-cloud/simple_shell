#include "shell.h"

/**
 * _exit - This exits the shell
 * @info: This is the structure containing potential arguments
 *          constant function prototype.
 *  Return: exits with a given exit status
 *         (0) if info.argv[0] != "exit"
 */
int _exit(info_t *info)
{
	int exit;

	if (infom->argv[1])
	{
		exit = _erroratoi(info->argv[1]);
		if (exit == -1)
		{
			info->status = 2;
			print_error(info, "Illegal number: ");
			_eputs(info->argv[1]);
			_eputchar('\n');
			return (1);
		}
		info->error_number = _erroratoi(info->argv[1]);
		return (-2);
	}
	info->error_num = -1;
	return (-2);
}

/**
 * _cd - This changes the current directory of the process
 * @infom: Structure containing potential arguments.
 *          constant function prototype.
 *  Return: Always 0
 */
int _cd(info_t *infom)
{
	char *str, *dir, buffer[1024];
	int chdir_ret;

	s = getcwd(buffer, 1024);
	if (!str)
		_puts("TODO: >>getcwd failure emsg here<<\n");
	if (!infom->argv[1])
	{
		dir = _getenv(info, "HOME=");
		if (!dir)
			chdir_ret =
				chdir((dir = _getenv(infom, "PWD=")) ? dir : "/");
		else
			chdir_ret = chdir(dir);
	}
	else if (_strcmp(infom->argv[1], "-") == 0)
	{
		if (!_getenv(infom, "OLDPWD="))
		{
			_puts(s);
			_putchar('\n');
			return (1);
		}
		_puts(_getenv(infom, "OLDPWD=")), _putchar('\n');
		chdir_ret =
			chdir((dir = _getenv(info, "OLDPWD=")) ? dir : "/");
	}
	else
		chdir_ret = chdir(info->argv[1]);
	if (chdir_ret == -1)
	{
		print_error(infom, "can't cd to ");
		_eputs(infom->argv[1]), _eputchar('\n');
	}
	else
	{
		_setenv(infom, "OLDPWD", _getenv(infom, "PWD="));
		_setenv(infom, "PWD", getcwd(buffer, 1024));
	}
	return (0);
}

/**
 * _help - This helps in changes the current directory of the process
 * @infom: The structure containing potential arguments.
 *          constant function prototype.
 *  Return: Returns 0
 */
int _help(info_t *infom)
{
	char **arg_array;

	arg_array = infom->argv;
	_puts("help call works. Function not yet implemented \n");
	if (0)
		_puts(*arg_array);
	return (0);
}
