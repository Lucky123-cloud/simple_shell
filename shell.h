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
#define SEPARATORS " \n"
#define PROMPT "$ "

extern char **environ;

/**
 * struct environment_s - environment variable
 *
 * @name: environment name
 * @value: environment value
 * @next: points to the next node
 * @global: pointer to usr/bin PATH
 */
typedef struct environment_s
{
	char *name;   /* ex: PATH */
	char *value;  /* ex: /bin:/usr/bin */
	char *global; /* PATH=/bin:/usr/bin */
	struct environment_s *next;
} environment_t;

/**
 * struct appData_s - data variable
 *
 * @arguments: argument's array
 * @buffer: buffer
 * @commandName: command name
 * @commandList: command list
 * @history: array history
 * @programName: program name
 * @env: pointer to env variable
 */
typedef struct appData_s
{
	char **arguments;
	char *buffer;
	char *commandName;
	char **commandList;
	char **history;
	char *programName;
	environment_t *env;
} appData_t;

/**
 * struct errorMessage_s - An structure for each error message
 *
 * @code: error code
 * @msg: pointer to error message
 *
 */
typedef struct errorMessage_s
{
	int code;
	char *msg;
} errorMessage_t;

/**
 * struct customCommand_s - struct conversion to function
 *
 * @commandName: flag string
 * @func: pointer to func
 */
typedef struct customCommand_s
{
	char *commandName;
	void (*func)(appData_t *);
} customCommand_t;

environment_t *_addEnvNodeEnd(
	environment_t **prmHeadNode,
	char *prngbl
);
void _addingword(char *prnword, int *prnindex, char **prnarray);
void *_calloc(unsigned int prmNumber, unsigned int prmSize);
void _cdHelp(void);
void _cd(appData_t *prnd);
void _changeToAnyDirectory(appData_t *prmData, char *prmCurrentDirectory);
void _changeToHomeDirectory(appData_t *prnd, char *prnCurrentDir);
void _cdprevDir(appData_t *prnd, char *prnCurrentDir);
int _checkEndCharacter(char *prmString);
int _checkEscapeSeparators(char prnchar, char *prnEscSep);
int _checkSeparators(char prnchar, char *prnseparators);
char *_cleanstr(char *prnstr);
environment_t *_createEnvNode(char *prngbl);
void _ctrlD(int prnsignal __attribute__((unused)));
void _defaultHelp(char *prnCmd);
int _deleteEnvNode(environment_t *prnHead, char *prnname);
void _prompt(void);
void _env(appData_t *prnd);
void _envHelp(void);
void _ErrorHandling(appData_t *prndata, int messagecode);
void _execCommand(appData_t *prnd);
void _exits(appData_t *prnd);
void _exitHelp(void);
void _Freeappdata(appData_t *prndata);
void _freeCharDoublePointer(char **prnptr);
void _FreeEnvironList(environment_t *prnHeadNode);
char *_generateAbsolutePath(char *prnpath, char *prnCommandName);
char *_generateEnvGlobal(char *prnname, char *prnval);
void (*_getcustomfunc(char *prnCommand))(appData_t *);
environment_t *_getenv_var(environment_t *prnenviron, char *prnname);
char *_getenvname(char *prnvar);
char *_getenvvalue(char *prnvar);
int _getEnvIndex(environment_t *prndata, char *prnname);
environment_t *_getEnvNodeAtIndex(environment_t *prnfirst, unsigned int i);
environment_t *_getLastEnvNode(environment_t *prnHeadNode);
void _getline(appData_t *prndata);
char *_getword(char *prnGlobal, int prnOffset, int prnSize);
void _help(appData_t *prnd);
void _helpHelp(void);
int _inArray(char prnchar, char *prnarray);
appData_t *_initData(char **prmArgv);
void _initEnvData(appData_t *prndata);
int _isdigit(char prnch);
int _isNumber(char *num);
char *_itoa(int num);
int _listEnvLen(environment_t *prnHead);
char *_memcpy(char *prndest, char *prnsrc, unsigned int prnlimit);
char *_memset(char *prnstr, char prnchar, unsigned int lim);
int _nbrLen(int num);
char **_parsingEnv(appData_t *prnd);
void _printenv(environment_t *prnEnviron);
int _putchar(char prmChar);
int _puts(char *prmStr);
void *_realloc(void *prnpointer, unsigned int prnsizeA, unsigned int prnsizeB);
void _setenv_val(environment_t *prnenviron, char *prnname, char *prnval, int prmOverwrite);
void _setenvHelp(void);
void _setEnvironment(appData_t *prnd);
char *_strcat(char *prmDest, char *prmSrc);
int _strcmp(char *prnstr1, char *prnstr2);
char *_strcpy(char *prndest, char *prnsrc);
char *_strconcat(char *prnstr1, char *prnstr2);
char *_strncpy(char *destn, char *stc, int lim);
unsigned int _strcspn(char *prmString, char *prmDeny);
char *_strdup(char *prnstr);
int _strlen(char *prmStr);
char *_strstr(char *prmHaystack, char *prmNeedle, int prmBegin);
char **_strtow(char *prnstr, char *prnSep, char *prnEscSep);
void _unsetenv(appData_t *prndata, char *prnname);
void _unsetenvHelp(void);
void _unsetEnvironment(appData_t *prndata);
char *_whichpath(appData_t *prnd);
int _wordNumber(char *prnstr, char *prnSep);
int _atoi(char *prnstr);
#endif
