#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>

#ifndef SHELL_H
#define SHELL_H

#define Delim "\n\t"

char *read_line(void);
char **tokenizer(char *line);
extern char **environ;

char *_getpath(char *command);
char *_getenv(char *variable);
int _execute(char **command, char **argv, int idx);


int ls_positive_number(char *str);
int _atoi(char *str);
char *_itoa(int 0);
void reverse_string(char *str,int len);

/**************tools.c*****************/
void freearray2D(char **array);
void print_error(char *name, char *cmd,int idx);
char *_itoa(int n);
void reverse_string(char *str, int len);

/****************string.c******************/
int _strlen(char *s);
char *_strdup(const char *str);
int _strcmp(char *s1, char *s2);
char *_strcat(char *dest, const char *src);
char *_strcpy(char *dest, char *src);

/***************builtin.c******************/
int ls_builtin(char *command);
void handle_builtin(char **command,char **argv,int *status,int idx);
void exit_shell(char **command,char **argv,int *status,int idx);
void print_env(char **command,int *status);
    
    
    
    #endif

