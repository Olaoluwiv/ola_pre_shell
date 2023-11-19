#include "shell.h"

/**
 *  * ls_builtin - check if the command is a builtin command
 *   * @command: the command to check
 *    * 
 *     * Return: 1 if the command is builtin, otherwise 0
 *      */
int ls_builtin(char *command)
{
	char *builtin[] = {"exit", "env", "setenv", "cd", NULL};
	
	int i;
	
	for (i = 0; builtin[i]; i++)
	
	{
		if (_strcmp(command, builtin[i]) == 0)
			return 1;
       	}
	
	return 0;
}

/**
 *  * handle_builtin - handle executive function of builtin shell
 *   * @command: the command argument
 *    * @status: the status update
 *     */
void handle_builtin(char **command, int *status)
{
	    if (_strcmp(command[0], "exit") == 0)
		            exit_shell(command, status);
	        else if (_strcmp(command[0], "env") == 0)
			        print_env(status);
		    
}

/**
 *  * exit_shell - handle the 'exit' built-in command
 *   * @command: the command argument
 *    * @status: the status update
 *     */
void exit_shell(char **command, int *status)
{
	    int exit_value = *status;
	        char *index, *mssg = ": exit illegal number";

		    if (command[1])
			    
			    if (_is_positive_number(command[1]))
			    
			    {
				    
				    exit_value = atoi(command[1]);
			    
			    }
			    
			    else
			    {
				    index = _itoa(exit_value);
				    if (index==NULL)   
					    freearray2D(command); 
				    *status=2;return;
				    write(STDERR_FILENO, command[0],_strlen(command[0]));
				    
				    write(STDERR_FILENO, ":", 1);
				    
				    write(STDERR_FILENO, index, _strlen(index));
				    write(STDERR_FILENO, mssg, _strlen(mssg));
				    write(STDERR_FILENO, command[1], _strlen(command[1]));
				    write(STDERR_FILENO, "\n", 1);
					    free(index);    
					    freearray2D(command);
					    *status = 2;
					    
					    return;
			    
			    }

}
freearray2D(command);  free(index);
exit(exit_value);
}

/**
 *  * print_env - handle the 'env' built-in command
 *   * @status: the status update
 *    */
void print_env(int *status)
{
	    int i;

	        for (i = 0; environ[i]; i++)
			    {
				            write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
					    write(STDOUT_FILENO, "\n", 1);
						        }

		    *status = 0;
}
