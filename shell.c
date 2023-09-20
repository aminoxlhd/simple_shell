#include "main.h"

/**
* run_shell - Function that run a shell command.
* the funciton will try to run the simple command, if it's not found, it'll look in the PATH.
* if not found will return -1.
*/
int run_shell(char ** command)
{
	char *environments[] = { NULL };
	int execution = 0;

	execution = execve(command[0] , command, environments);

	if (execution == -1)
	{
		char * command_with_path = get_path(command[0]);

		if (command_with_path == NULL)
		{
			return (-1);
		}
		execution = execve(command_with_path, command, environments)
	}

	return (execution);
}
