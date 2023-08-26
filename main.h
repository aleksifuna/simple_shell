#ifndef MAIN_H
#define MAIN_H
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stddef.h>
#include <string.h>
extern char **environ;
char ** token(char *str, char sep, char end);
void freestarr(char **str);
int str_len( char *str, char term);
int array_len(char **str);
char *file_link(char *string);
char **_which(char *arg_str);
char *get_path(void);
int arg_count(char *arg_string, char sep, char end);
void exit_function(char **exit_args, size_t no_of-args);
int _atoi(char *s);
void return_comments(char *buf);
int _srncmp(char *str1, char *str2)
#endif /* MAIN_H */
