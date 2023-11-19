#include "shell.h"

/**
 *  * main - Simple shell function
 *   * @ac: Count of arguments
 *    * @av: Arguments
 *     * Return: 0 Always (success)
 *      */
int main(int ac, char **av)
{
	    char *line = NULL, **commands = NULL;
	    int status = 0, idx = 0;
	    
	    (void)ac;
	    (void)av;
	    
	    while (1)
	    {
		    
		    line = read_line();
		    
		    if (line == NULL)
		    
		    {
			   
			    /* Reached EOF (Ctrl + D) */
			    
			    if (isatty(STDIN_FILENO))
				    
				    write(STDOUT_FILENO, "\n", 1);
			    
			    return status;
		    
		    }
		    
		    idx++;
		    
		    commands = tokenizer(line);
		    
		    if (!commands)
			    
			    continue;
		    
		    for (int i = 0; commands[i]; i++)
		    {
			    
			    if (commands[i] == NULL)
				    return status;
			    
			    if (ls_builtin(commands[i]))
				    
				    handle_builtin(commands[i], av, &status, idx);
			    
			    else
				    
				    status = _execute(commands[i], av, idx);
		    
		    }
		    
		    free(line);  // Free memory allocated by read_line
		    free(commands);  // Free memory allocated by tokenizer
				        }
		return 0;


}
