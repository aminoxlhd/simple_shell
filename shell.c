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
	char *environments[] = { NULL };
	int execution = 0;
	char *command_with_path = get_path(command[0]);

	execution = execve(command[0] , command, environments);

	if (execution == -1)
	{
		char * command_with_path = get_path(command[0]);

		if (command_with_path == NULL)
		{

		return (-1);
		}

		execution = execve(command_with_path, command, environments);
	}
	return (execution);
}
