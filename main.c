#include "main.h"

/**
 * main - Entry Point.
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	size_t bufsize = 1024;
	char *binaryPath;
	char **args;
	int i = 0, status = 0;

	while (1)
	{
		printf(":) ");
		binaryPath = (char *) malloc(bufsize * sizeof(char));
		getline(&binaryPath, &bufsize, stdin);
		remove_last_newline(binaryPath);
		args = split_arguments(binaryPath, " ");
		if (check_command(args[0]) == 1)
		{
			if (strcmp(args[0], "exit") == 0)
			{
				status = handle_exit(args);
				break;
			}
			if (strcmp(args[0], "env") == 0)
			{
				i = 0;
				while (environ[i])
				{
					printf("%s\n", environ[i]);
					i++;
				}
				continue;
			}
			run_command(args);
		} else
		{
			print_error(args[0]);
		}
		free(binaryPath);
	}
	return (status);
}

/**
 * handle_exit - a function that will be called
 * when we type exit in the command line
 * @args : the command line we typed.
 * Return: 0 if there is no status
 * status if we add a status to exit (e.g exit 3)
 */
int handle_exit(char **args)
{
	int sizeOfArgs = 0, i = 0, status = 0;

	for (i = 0; args[i] != NULL; i++)
		sizeOfArgs++;
	if (sizeOfArgs == 2)
		status = atoi(args[1]);
	return (status);
}

/**
 * run_command - a function that will create a fork
 * and run the command, if the command doesn't exists
 * it'll print an error
 * @args : tokenized command with arguments.
 */
void run_command(char **args)
{
	pid_t pid;

	pid = fork();
	if (pid == 0)
	{
		int exec = run_shell(args);

		if (exec == -1)
			print_error(args[0]);
		exit(1);
	} else
	{
		wait(NULL);
	}
}

/**
 * print_error - Function that prints the error if a command isn't found.
 * @command : a string which is the command.
 */
void print_error(char *command)
{
	char *shell = getenv("SHELL");

	printf("%s", shell);
	printf(": 1: ");
	printf("%s", command);
	printf(": not found\n");
}
