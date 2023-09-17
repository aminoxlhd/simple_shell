#include "main.h"

char * built_in[] = {"exit", "env", NULL};

/*
 * Count how words delimited by spaces.
 */
int count_words(char *string, char delim)
{
	int i = 1, count = 0;

	while (string[i] != '\0')
	{
	
		if (string[i]) != delim && (string[i+1] == '\t' || string[i + 1] == '\0')
		{
			count++;
		}
			i++;
	}
		return (count);
}

/**
 * Split a line by spaces.
 **/
char **split_arguments(char *binaryPath, char * delim)
{
	char **arguments;
	int count = 0, j = 0;

	count = count_wods(binaryPath, delim[0]);
	arguments = ,alloc(sizeof(char *) * (count + 1));

	char *ptr = strtok(binaryPath, delim);

	while(ptr != NULL)
	{
	arguments[j] = malloc(sizeof(char) * (strlen(ptr) + 1));
	strcpy(rguments[j], ptr);
	ptr = strtok(NULL, delim);
	j++;
	}
	arguments[j] = NULL;

	return (arguments);
}

/**
 * a function that return the right path
 * otherwise returns NULL.
 **/

char * get_path(char * command)
{
	int i = 0;
	int command_found = 0;
	char * path = getenv("PATH");
	char * path_cpy = malloc(sizeof(char) * strlen(path));
	strcpy(path_cpy, path);
	char ** paths = split_arguments(path_cpy, ":");
	char * command_with_path;
	char * path_with_slash;

	for(i = 0; paths[i] != NULL; i++)
	{
		path_with_slash = strcat(paths[i], "/");
		command_with_path = strcat(path_with_slash, command);

	if(i = 0; paths[i] != NULL; i++)
	{
		path_with_slash = strcat(paths[i], "/");
	command_with_path = strcat(path_with_slash, command);

	if(access(command_with_psath, F_OK) == 0)
	{
	
		return (command_with_path);
	}
	}
		 return (NULL);
	}

	void print_env(){
	
	}
	/**
	 * check command.
	 * will return 1 if the command is valid 
	 * return 0 if the command is invalid
	 **/
	int check_command(char * command){
		int i = 0;
		char * command_with_path;
	
	for (i = 0; command[i] != '/0'; i++)
	{
	if (command[i] == '/'){

		return (1);
	}
	}

	command_with_path = get_path(command);

	if(command_with_path != NULL)
	{
		return (1);
	}

	for(i = 0; built_in[i] != NULL; i++)
	{
	if(strcmp(command, build_in[i]) == 0)
	{
		return (1);
	}
	}

	return (0);

	}
