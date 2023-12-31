#include "main.h"

/**
 * main - Entry Point.
 * @argc: number of arguments
 * @argv: arguments
 * Return: Always 0 (Success)
 */
int main(int argc, char *argv[])
{
	size_t bufsize = 1024;
	char *binaryPath;
	char **args;
	int  status = 0;
	(void)argc;
	if (isatty(STDIN_FILENO) != 1)
		status = passive(argv[0]);
	else
	{
		while (1)
		{
			m_puts("$ ");
			binaryPath = (char *) malloc(bufsize * sizeof(char));
			getline(&binaryPath, &bufsize, stdin);
			if (strlen(binaryPath) == 0)
				break;
			remove_last_newline(binaryPath);
			args = split_arguments(binaryPath, " \t\r\n\a\"");
			if (check_command(args[0]) == 1)
			{
				if (strcmp(args[0], "exit") == 0)
				{
					status = handle_exit(args);
					break;
				}
				if (strcmp(args[0], "env") == 0)
				{
					print_env();
					continue;
				}
				run_command(argv[0], args);
			} else
			{
				print_error(argv[0], args[0]);
			}
			free(binaryPath);
		}
	}
	return (status);
}

/**
 * print_env - a function that will print
 * the env variables
 **/
void print_env(void)
{
	int i = 0;

	while (environ[i])
	{
		m_puts(environ[i]);
		m_puts("\n");
		i++;
	}
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
 * @args: tokenized command with arguments.
 * @shell: shell
 * Return: the status
 */
int run_command(char *shell, char **args)
{
	pid_t pid;
	int status, exec = 0;

	pid = fork();
	if (pid == 0)
	{
		exec = run_shell(args);

		if (exec == -1)
		{
			print_error(shell, args[0]);
			free(args);
			exit(127);
		}
		free(args);
		exit(1);
	} else
	{
		waitpid(pid, &status, WUNTRACED);
		exec = WEXITSTATUS(status);
	}

	return (exec);
}

/**
 * print_error - Function that prints the error if a command isn't found.
 * @command: the command.
 * @shell: shell
 */
void print_error(char *shell, char *command)
{
	fprintf(stderr, "%s: 1: %s: not found\n", shell, command);
}
