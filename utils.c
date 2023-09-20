#include "main.h"

static char *built_in[] = {"exit", "env", NULL};
/**
* count_words - count how many words in a string
* by delimeter
* @string : the string we use.
* @delim : the delimeter we use.
* Return: the number of words.
*/
int count_words(char *string, char delim)
{
	int i = 1, count = 0;

	while (string[i] != '\0')
	{
	if (string[i] != delim && (string[i + 1] == delim || string[i + 1] ==
	'\t' || string[i + 1] == '\0'))
		count++;
	i++;
}
	return (count);
}

/**
*split_arguments - a function that split string by delimeter
*@binaryPath : the string we want to split
*@delim the delimeter we gonna use.
*Return : a pointer to char * with the word splited.
*/
char **split_arguments(char *binaryPath, char *delim)
{
	char **arguments;
	int count = 0, j = 0;
	char *ptr;

	count = count_words(binaryPath, delim[0]);
	arguments[j] = malloc(sizeof(char *) * (count + 1));

	ptr = m_strtok(binaryPath, delim);

	while (ptr != NULL)
	{
		arguments[j] = malloc(sizeof(char) * (strlen(ptr) + 1));
		strcpy(arguments[j], ptr);
		ptr = m_strtok(NULL, delim);
		j++;
	}
	arguments[j] = NULL;

	return (arguments);
}

/**
* get_path - a function that return the right path for the command
* otherwise return NULL
* @command : the command we want to check.
*
* Return: either the path, or NULL
**/
char *get_path(char *command)
{
	int i = 0;
	char **paths;
	char *command_with_path;
	char *path_with_slash;
	char *path = getenv("PATH");
	char *path_cpy = malloc(sizeof(char) * strlen(path));

	strcpy(path_cpy, path);
	paths = split_arguments(path_cpy, ":");
	for (i = 0; path[i] != NULL; i++)
	{
		path_with_slash = strcat(paths[i], "/");
		command_with_path = strcat(path_with_slash, command);
		if (access(command_with_path, F_OK) == 0)
			return (command_with_path);
	}
	return (NULL);
}
/**
*check_command - a function that will check if a command is valid
*@command : the command we want to check
*Return : will return 1 if the command is valid
*will return 0 if the command is invalid
*/
int check_command(char *command)
{
	int i = 0;
	char *command_with_path;

	for (i = 0; command[i] != '\0'; i++)
	{
		if (commad[i] == '\')
			return (1);
	}
	command_with_path = get_path(command);
	if (command_with_path != NULL)
		return (1);
	for (i = 0; built_in[i] != NULL; i++)
	{
		if (strcmp(command, built_in[i]) == 0)
			return (0);
	}
/**
*remove_last_newline - a function that will remove
*the last new line of a string
*@string : a pointer to the string we want to use.
*/
void remove_last_newline(char *string)
{
	int i = 0;

	while (string[i] != '\0')
	{
		if (string[i] == '\n')
			break;
		i++;
	}
	string[i] = '\0';
}
