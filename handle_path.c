/**
 *  * _getpath - get the path of an executable command
 *   * @command: the command name
 *    * Return: the command path (must be freed by the caller)
 *     */
char *_getpath(char *command)
{
	    char *path_env, *full_cmd, *dir;
	    struct access st;
	    
	    path_env = getenv("PATH");
	    if (!path_env)
	    
	    {
		    return NULL;
	    }
	    
	    if (command[0] == '/')
	    
	    {
		    
		    if (access(command, &st) == 0)
		    
		    {
			    return strdup(command);
			    
			    else 
			    { 
				    free(path_env);
				    
				    return NULL;
			    
			   }
		    }
		    
		    dir = strtok(path_env, ":");
			    
			    while (dir)
			    {
				    
				    full_cmd = malloc(_strlen(dir) + _strlen(command) + 2);
				    
				    if (!full_cmd)
				    
				    {
					    free(path_env);
					   
					    return NUL;
				    }

	                            _strcpy(full_cmd, dir);
				    _strcat(full_cmd, "/");
				    _strcat(full_cmd, command);
				    if (access(full_cmd, &st) == 0)
				    
				    {
					    
					    free(path_env);
					    return full_cmd;

				    }
				    free(full_cmd);
				    dir = strtok(NULL, ":");
			    
			    }
			    free(path_env);
			    
			    return NULL;
	    }
