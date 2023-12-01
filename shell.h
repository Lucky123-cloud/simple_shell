#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#define BUFFER_SIZE 256
#define ENV_SEPARATOR "="
#define ESCAPE_SEPARATOR "#"
#define PATH_SEPARATOR ":"
#define COMMAND_SEPARATOR ";\n"
#define SEPARATORS "\n"
#define PROMPT "$"

#endif
