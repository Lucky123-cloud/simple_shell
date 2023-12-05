#include "shell.h"
/**
 * _parsingEnv - breaks down commands to ind components
 * @prnd: prints data
 * Return: returns value
 */
char **_parsingEnv(appData_t *prnd)
{
	char **v;
	environment_t *node;

	node = _getenv_var(prnd->env, "PATH");
	v = _strtow(node->value, PATH_SEPARATOR, NULL);

	return (v);
}
