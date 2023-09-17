#ifndef SHELL_H
#define SHELL_H

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<dirent.h>
#include<sys/wait.h>

#define BUF_S 1024

int check_commands(char **src, char **envp);
char *print_prompt(void);
char **get_commands(char *line);
char *get_path(char **command);

char *expo_loc(char *argument);
char *get_loc(char *path, char *argument);

char *_strcpy_c(char *input, char *src);
char **list_of_items(char *str, char *dels);
int _strcmp(char *s1, char *s2);
char *_strtok(char *str, const char *dels);
int _strlen(char *s);

int _putchar(char c);
int _puts(char *s);

#endif
