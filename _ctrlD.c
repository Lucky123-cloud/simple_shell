#include "shell.h"

/**
 * _ctrlD - controls the moving from one place another
 *
 * @prnsignal: This tells the signal value
 *
 * Return: It returns nothing in particular(void)
 */
void _ctrlD(int prnsignal __attribute__((unused)))
{
	_puts("\n");
	_prompt();
}
