#include "shell.h"


#define DELIM " \t\r\n\a"

/**
 *  * tokenizer - tokenize a string into an array of tokens
 *   * @line: the string to tokenize
 *    * Return: An array of tokens
 *     */
char **tokenizer(char *line)
{
	    char *token, *tmp;
	    char **command;
	    int cpt = 0, i = 0;
	    
	    if (!line)
		    
		    return NULL;
	    
	    tmp = strdup(line);
	    
	    token = strtok(tmp, DELIM);
	    
	    while (token)
	    
	    {
		    
		    cpt++;
		    
		    token = strtok(NULL, DELIM);
	    
	    }
	    
	    free(tmp);
	    
	    command = (char **)malloc(sizeof(char *) * (cpt + 1));
	    
	    if (!command)
		    
		    return NULL;
	    
	    token = strtok(line, DELIM);
	    
	    while (token)
	    
	    {
		    
		    command[i] = strdup(token);
		    
		    if (!command[i])
		    
		    {
			    
			    for (int j = 0; j < i; j++)
				    
				    free(command[j]);
			    
			    free(command);
			    
			    return NULL;
		    }
		    token = strtok(NULL, DELIM);
		    
		    i++;
	    }
	    
	    free(line);
	    command[i] = NULL;
	    
	    return command;
}

