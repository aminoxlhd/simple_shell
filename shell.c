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
