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
#include <string.h>
extern char **environ;
char **token(char *str, char sep, char end);
void freestarr(char **str);
int array_len(char **str);
char *file_link(char *string);
char **_which(char *arg_str);
char *get_path(char *en_var);
int arg_count(char *arg_string, char sep, char end);
<<<<<<< HEAD
void exit_function(char **exit_args, size_t no_of-args);
int _atoi(char *s);
void return_comments(char *buf);
int _srncmp(char *str1, char *str2)
=======
void shell_exit(char *str);
int string_int(char *string);
char *get_line(void);
char *link_const(char *dlink, char *command);
char *ni_get_line(char **input, int *idx);
int str_len(char *str, char term);
void free_memory(char *str, char **arry);
void handle_error(void);
void free_string_memory(char **str, char **arry);
>>>>>>> a59dfc36e243633641387c2726e48979a3948cb0
#endif /* MAIN_H */
