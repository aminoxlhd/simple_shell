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

char *read_input(void)
{
	int i = 0, bufferSize = 1024;
	char *binaryPath = malloc(sizeof(char) * bufferSize);
	char character;

	while(1)
	{
		character = getchar();
		if(character == '\n'){
			binaryPath[i] = '\0';
			return binaryPath;
		}
		else if (character == EOF)
			free(binaryPath);
		else
			binaryPath[i] = character;
		i++;
	}
}


int passive(char *shell)
{
	char *binaryPath;
	char **args;
	int status;

	binaryPath = read_input();
	args = split_arguments(binaryPath, " \t\r\n\"");
	status = run_command(shell, args);
	free(binaryPath);
	free(args);

	return status;
}

