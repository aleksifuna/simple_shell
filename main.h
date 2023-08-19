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
extern char **environ;
char ** token(char *str, char sep, char end);
void freestarr(char **str);
int str_len( char *str, char term);
int array_len(char **str);
char *file_link(char *string);
char **_which(char *arg_str);
char *get_path(void);
int arg_count(char *arg_string, char sep, char end);
#endif /* MAIN_H */
