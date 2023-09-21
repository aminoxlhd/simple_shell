#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define _GNU_SOURCE
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
extern char **environ;
int run_shell(char **command);
char **split_arguments(char *str, char *delim);
char *get_path(char *command);
int check_command(char *command);
void print_env(void);
void remove_last_newline(char *string);
void custom_getline(char *string);
void run_command(char *shell, char **args);
void print_error(char *shell, char *command);
char *m_strtok(char *string, const char *delim);
int handle_exit(char **args);
int m_puts(char *string);
void m_getline(char *string);
void print_env(void);
#endif
