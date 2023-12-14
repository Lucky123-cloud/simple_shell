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
int add(int a, int b);
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
void _setenv_val(environment_t *prnenv, char *prnm, char *prval, int prOvrwrt);
void _setenvHelp(void);
void _setEnvironment(appData_t *prnd);
char *_strcat(char *prmDest, char *prmSrc);
int _strcmp(char *prnstr1, char *prnstr2);
char *_strcpy(char *prndest, char *prnsrc);
char *_strconcat(char *prnstr1, char *prnstr2);
char *_strncpy(char *prndest, char *prnsrc, int prnlim);
unsigned int _strcspn(char *prmString, char *prmDeny);
char *_strdup(char *prnstr);
int _strlen(char *prmStr);
char *_strstr(char *prmHaystack, char *prmNeedle, int prmBegin);
char **_strtow(char *prnstr, char *prnSep, char *prnEscSep);
void _unsetenv(appData_t *prndata, char *prnname);
void _unsetenvHelp(void);
void _unsetEnviron(appData_t *prndata);
char *_whichpath(appData_t *prnd);
int _wordNumber(char *prnstr, char *prnSep);
int _atoi(char *prnstr);

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

/* for read/write buffers */
#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1

/* for command chaining */
#define CMD_NORM 0
#define CMD_OR 1
#define CMD_AND 2
#define CMD_CHAIN 3

/* for convert_number() */
#define CONVERT_LOWERCASE 1
#define CONVERT_UNSIGNED 2

/* 1 if using system getline() */
#define USE_GETLINE 0
#define USE_STRTOK 0

#define HIST_FILE ".simple_shell_history"
#define HIST_MAX 4096

extern char **environ;

/**
 * struct liststr - singly linked list
 * @num: the number field
 * @str: a string
 * @next: points to the next node
 */
typedef struct liststr
{
	int num;
	char *str;
	struct liststr *next;
} list_t;

/**
 *struct passinfo - contains pseudo-arguements to pass into a function,
 *		allowing uniform prototype for function pointer struct
 *@arg: a string generated from getline containing arguements
 *@argv: an array of strings generated from arg
 *@path: a string path for the current command
 *@argc: the argument count
 *@line_count: the error count
 *@err_num: the error code for exit()s
 *@linecount_flag: if on count this line of input
 *@fname: the program filename
 *@env: linked list local copy of environ
 *@environ: custom modified copy of environ from LL env
 *@history: the history node
 *@alias: the alias node
 *@env_changed: on if environ was changed
 *@status: the return status of the last exec'd command
 *@cmd_buf: address of pointer to cmd_buf, on if chaining
 *@cmd_buf_type: CMD_type ||, &&, ;
 *@readfd: the fd from which to read line input
 *@histcount: the history line number count
 */
typedef struct passinfo
{
	char *arg;
	char **argv;
	char *path;
	int argc;
	unsigned int line_count;
	int err_num;
	int linecount_flag;
	char *fname;
	list_t *env;
	list_t *history;
	list_t *alias;
	char **environ;
	int env_changed;
	int status;

	char **cmd_buf;	  /* pointer to cmd ; chain buffer, for memory mangement */
	int cmd_buf_type; /* CMD_type ||, &&, ; */
	int readfd;
	int histcount;
} info_t;

#define INFO_INIT                                                               \
	{                                                                           \
		NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
			0, 0, 0                                                             \
	}

/**
 *struct builtin - contains a builtin string and related function
 *@type: the builtin command flag
 *@func: the function
 */
typedef struct builtin
{
	char *type;
	int (*func)(info_t *);
} builtin_table;

/* shloop.c */
int hsh(info_t *, char **);
int find_builtin(info_t *);
void find_cmd(info_t *);
void fork_cmd(info_t *);

/* parser.c */
int is_cmd(info_t *, char *);
char *dup_chars(char *, int, int);
char *find_path(info_t *, char *, char *);

/* loophsh.c */
int loophsh(char **);

/* errors.c */
void _eputs(char *);
int _eputchar(char);
int _putfd(char c, int fd);
int _putsfd(char *str, int fd);

/* string.c */
int _strlen(char *);
int _strcmp(char *, char *);
char *starts_with(const char *, const char *);
char *_strcat(char *, char *);

/* string1.c */
char *_strcpy(char *, char *);
char *_strdup(const char *);
void _puts(char *);
int _putchar(char);

/* exits.c */
char *_strncpy(char *, char *, int);
char *_strncat(char *, char *, int);
char *_strchr(char *, char);

/* tokenizer.c */
char **strtow(char *, char *);
char **strtow2(char *, char);

/* realloc.c */
char *_memset(char *, char, unsigned int);
void ffree(char **);
void *_realloc(void *, unsigned int, unsigned int);

/* memory.c */
int bfree(void **);

/* atoi.c */
int interactive(info_t *);
int is_delim(char, char *);
int _isalpha(int);
int _atoi(char *);

/* errors1.c */
int _erratoi(char *);
void print_error(info_t *, char *);
int print_d(int, int);
char *convert_number(long int, int, int);
void remove_comments(char *);

/* builtin.c */
int _myexit(info_t *);
int _mycd(info_t *);
int _myhelp(info_t *);

/* builtin1.c */
int _myhistory(info_t *);
int _myalias(info_t *);

/*getline.c */
ssize_t get_input(info_t *);
int _getline(info_t *, char **, size_t *);
void sigintHandler(int);

/* getinfo.c */
void clear_info(info_t *);
void set_info(info_t *, char **);
void free_info(info_t *, int);

/* environ.c */
char *_getenv(info_t *, const char *);
int _myenv(info_t *);
int _mysetenv(info_t *);
int _myunsetenv(info_t *);
int populate_env_list(info_t *);

/* getenv.c */
char **get_environ(info_t *);
int _unsetenv(info_t *, char *);
int _setenv(info_t *, char *, char *);

/* history.c */
char *get_history_file(info_t *info);
int write_history(info_t *info);
int read_history(info_t *info);
int build_history_list(info_t *info, char *buf, int linecount);
int renumber_history(info_t *info);

/* lists.c */
list_t *add_node(list_t **, const char *, int);
list_t *add_node_end(list_t **, const char *, int);
size_t print_list_str(const list_t *);
int delete_node_at_index(list_t **, unsigned int);
void free_list(list_t **);

/* lists1.c */
size_t list_len(const list_t *);
char **list_to_strings(list_t *);
size_t print_list(const list_t *);
list_t *node_starts_with(list_t *, char *, char);
ssize_t get_node_index(list_t *, list_t *);

/* vars.c */
int is_chain(info_t *, char *, size_t *);
void check_chain(info_t *, char *, size_t *, size_t, size_t);
int replace_alias(info_t *);
int replace_vars(info_t *);
int replace_string(char **, char *);
#endif
