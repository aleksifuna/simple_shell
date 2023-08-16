#ifndef MAIN_H
#define MAIN_H
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>
char ** token(char *str, char sep, char end);
void freestarr(char **str);
int str_len( char *str, char term);
#endif /* MAIN_H */
