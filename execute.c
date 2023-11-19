#include "shell.h"

/**
  * _execute - execute command
 * @command: arguments of command
 * @argv: array of arguments
 * @idx: command index of input
 * Return: return command
 */
int _execute(char **command, char **argv, int idx)
{
	    char *full_cmd;
	    pid_t child;
	    int status;
	    
	    full_cmd = _getpath(command[0]);
	    
	    if (!full_cmd)
	    
	    {
		    
		    print_error(argv, 0, command[0], idx);
		    
		    free_array2D(command);
		    
		    return (127);
	    
	    }
	    
	    child = fork();
	    
	    if (child == 0)
	    
	    {
		    
		    if (execve(full_cmd, command, environ) == -1)
		    
		    {
			    perror("execve");  
			    exit (127);
		    
		    }
	    }
	    
	    else
	    
	    {
		    
		    waitpid(child, &status, 0);
		    
		    free_array2D(command);
		    free(full_cmd), full_cmd = NULL;
		    return (WEXITSTATUS(status));
	    }
}
