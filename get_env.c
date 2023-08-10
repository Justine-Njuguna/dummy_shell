#include <stdio.h>
#include <stdlib.h>

/* Define the environ global variable */
extern char **environ;

/**
 * _getenv - Get the value of an environment variable
 * @name: The name of the environment variable
 * Return: The value of the environment variable, or NULL if not found
 */
char *_getenv(const char *name)
{
	char **env = environ;

    while (*env != NULL)
    {
	    char *env_var = *env;
	    int i = 0;
	
	while (name[i] != '\0' && env_var[i] == name[i])
	{
		i++;
	}
	
	if (name[i] == '\0' && env_var[i] == '=')
	{
		return &env_var[i + 1];
	}
	env++;
    }
    
    return (NULL);
}

/**
 * main - Entry point of the program
 * Return: Always 0 (Success)
 */
int main(void)
{
	char *log_dir = _getenv("LOG_DIR");
	
	if (log_dir != NULL)
    {
	    printf("LOG_DIR:\n%s\n", log_dir);
    }
    else
    {
	    printf("LOG_DIR not found.\n");
    }

    return (0);
}
