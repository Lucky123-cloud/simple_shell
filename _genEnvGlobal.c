#include "shell.h"

/**
 * _generateEnvGlobal - main function that generates variable
 * from name and value
 *
 * @prnname: The name of the environment
 * @prnval: THe value of the environment
 *
 * Return: Returns global environment variable
 */
char *_generateEnvGlobal(char *prnname, char *prnval)
{
	char *tmp, *gbl;

	gbl = "";
	gbl = _strconcat(gbl, prnname);
	tmp = _strconcat(gbl, "=");
	free(gbl);
	gbl = _strconcat(tmp, prnval);
	free(tmp);

	return (gbl);
}
