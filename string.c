#include "shell.h"

/**
 *  * _strdup - duplicate a string
 *   * @str: the string to duplicate
 *    * Return: A pointer to the duplicated string
 *     */
char *_strdup(const char *str)
{
	    char *ptr;
	    int i, len = 0;
	    
	    if (str == NULL)
		    return (NULL);
	    
	    while (str[len])
		    
		    len++;
	    
	    ptr = malloc(sizeof(char) * (len + 1));
	    
	    if (ptr == NULL)
		    
		    return (NULL);
	    
	    for (i = 0; i < len; i++)
		    
		    ptr[i] = str[i];
	    
	    ptr[len] = '\0';
	    return (ptr);
}

int _strcmp(char *s1, char *s2)
{
	int cmp;
	cmp = (int)*s1 - (int)*s2;
	
	while (*s1)
	
	{
		
		if (*s1 != *s2)
			
			break;
		s1++;
		
		s2++;
		
		cmp = (int)(*s1) - (int)(*s2);
	
	}
	
	return (cmp);
}

size_t _strlen(char *s)
{
	
	size_t  len = 0;
	
	while (s[len])
		
		len++;
	
	return (len);
}

char *_strcat(char * const dest, const char *src)
{
	    char *p = dest;
	    
	    while (*p)
		    
		    p++;
	    
	    while (*src)
	    
	    {
		    *p = *src;
		    p++;
		    src++;
	    }
	    
	    *p = '\0';
	   
	    return (dest);
}

char *_strcpy(char *dest, const char *src)
{
	    int i = 0;
	    
	    while (src[i])
	    
	    {
		    
		    dest[i] = src[i];
		    
		    i++;
	    }
	    
	    dest[i] = '\0';
	    
	    return  (dest);
}

