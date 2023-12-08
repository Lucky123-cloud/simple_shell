#include "shell.h"

/**
 * _defaultHelp - helps in printimg help if any command is not found
 * @prnCmd: This is the command name
 */
void _defaultHelp(char *prnCmd)
{
	_puts("bash: help: Aucune rubrique d'aide ne correspond à \"");
	_puts(prnCmd);
	_puts("\". Essayez \"help help\", \"man -k ");
	_puts(prnCmd);
	_puts("\" ou \"info ");
	_puts(prnCmd);
	_puts("\".\n");
}
