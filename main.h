#ifndef MAIN_H
#define MAIN_H
#define BUFFER_SIZE 1024
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stddef.h>
extern char **environ;
char **token(char *str, char sep, char end);
void freestarr(char **str);
int array_len(char **str);
char *file_link(char *string);
char **_which(char *arg_str);
char *get_path(char *en_var);
int arg_count(char *arg_string, char sep, char end);
void shell_exit(char *str);
int string_int(char *string);
char *get_line(void);
char *link_const(char *dlink, char *command);
char *ni_get_line(char **input, int *idx);
int str_len(char *str, char term);
void free_memory(char *str, char **arry);
#endif /* MAIN_H */
