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
int run_shell(char ** command);
char ** split_arguments(char *str, char * delim);
char * get_path(char * command);
int check_command(char * command);
void print_env();
void remove_last_newline(char * string);
void custom_getline(char * string);
void print_error(char * command);

typedef struct Alias {
    char *name;
    char *value;
} Alias;

void manage_aliases(void);
void add_alias(char *name, char *value);
void print_aliases();
void remove_alias(const char *name)

#endif
