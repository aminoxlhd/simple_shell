#include "main.h"

int main(int argc, char *argv[])
{
	size_t bufsize = 1024;
	char *binaryPath;
	char **args;
	pid_t pid;
	int i = 0;

	while (1)
	{
		printf("#cisfun$ ");
		binaryPath = (char *) malloc(bufsize * sizeof(char))
		getline(&binaryPath, &bufsize, stdin);
		remove_last_newline(binaryPath);
		agrs = split_arguments(binaryPath, " ");

		if (check_command(args[0]) == 1)
		{
		if (strcmp(args[0], "exit") == 0)
		{
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

		pid = fork();
		if (pid == 0)
		{
			int exec = run_shell(agrs);

			if (exec == -1)
			{
				print_error(agrs[0]);
			}
			exit(1);
		}
		else
		{
			wait(NULL);
		}
		}
		else
		{
			print_error(args[0]);
		}
		free(binaryPath);
	}
	return (0);
}

void print_error(char *command)
{
	char *shell = getenv("SHELL");

	printf("%s", shell);
	printf(": 1: ");
	printf("%s", command);
	printf(": not found\n");
}
