#include "main.h"

/**
* run_shell - Function that runs a shell command.
* @command: An array of strings representing
* the command and its arguments.
*
* This function will try to run the simple command.
* If it's not found,it'll look in the PATH.
*
* Return: If the execution is successful, it returns
* the exit status.If there's an error, it returns -1.
*/
int run_shell(char **command)
{
	int execution = 0;

	execution = execvp(command[0], command);

	return (execution);
}

/**
 * read_input : a function that reads the input
 * character by character and stops at EOF
 * Return: the readed line.
 **/
char *read_input(void)
{
	int i = 0, bufferSize = 1024;
	char *binaryPath = malloc(sizeof(char) * bufferSize);
	char character;

	while (1)
	{
		character = getchar();
		if (character == -1)
		{
			free(binaryPath);
			return NULL;
		}
		if (character == '\n')
		{
			binaryPath[i] = '\0';
			return (binaryPath);
		}
		else
			binaryPath[i] = character;
		i++;
	}
}

/**
 * passive - a function run in the passive mode.
 * @shell: the shell wei run in case of errors.
 * Return: the status of the executed command.
 **/
int passive(char *shell)
{
	char *binaryPath;
	char **args;
	int status;

	binaryPath = read_input();
	while (binaryPath != NULL)
	{
		args = split_arguments(binaryPath, " \t\r\n\"");
		status = run_command(shell, args);
		free(binaryPath);
		free(args);
		binaryPath = read_input();
	}
	return (status);
}

