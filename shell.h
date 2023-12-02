#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

#define PROMPT char * "#"
void _prompt(void);
int _putchar(char prnchar);
int _puts(char *prnstr);

#endif
