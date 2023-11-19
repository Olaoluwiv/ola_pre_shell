#include "shell.h"

void freearray20(char **array)
{
	    int i;
	    if (!array)
		    return;
	    
	    for (i = 0; array[i]; i++)
	    
	    {
		    
		    free(array[i]);
		    
		    array[i] = NULL;
	    
	    }
		        free(array);
			
			array = NULL;
}

/**
 *  * print_error - an error message to standard error
 *   * @name: the name of the char
 *    * @cmd: the error command
 *     * @idx: the index of the command
 *      */
void print_error(char *name, char *cmd, size_t idx)
{
	    char *index = _itoa(idx);

	        write(STDERR_FILENO, name, _strlen(name));
	        write(STDERR_FILENO, ":", 1);
		write(STDERR_FILENO, index, _strlen(index));
	        write(STDERR_FILENO, ":", 1);
		write(STDERR_FILENO, cmd, _strlen(cmd));
		write(STDERR_FILENO, ": not found\n", 13);
		
		free(index);
}

char *_itoa(size_t n)
{
	    char buffer[20];
	        int i = 0;
		
		if (n == 0)
		buffer[i++] = '0';
		
		else
		
		{
			
			while (n > 0)
			{
				buffer[i++] = (n % 10) + '0';
				
				n /= 10;
			
			}
		}
		
		buffer[i] = '\0';
		
		reverse_string(buffer, i);
		
		return _strdup(buffer);
}

void reverse_string(char *str, int len)
{
	    char tmp;
	        int start = 0;
		int end = len - 1;

		while (start < end)
		{
			
			tmp = str[start];
			
			str[start] = str[end];
			
			str[end] = tmp;
			start++;
			
			end--;
		
		}
}
