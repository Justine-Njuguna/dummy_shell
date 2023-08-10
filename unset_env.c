#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern char **environ;

/**
 * _unsetenv - Deletes an environment variable from the environment
 * @name: The name of the environment variable to delete
 * Return: 0 on success, -1 on failure
 */
int _unsetenv(const char *name)
{
    if (name == NULL || name[0] == '\0' || strchr(name, '=') != NULL)
        return -1;

    int env_count = 0;
    while (environ[env_count] != NULL)
        env_count++;

    for (int i = 0; i < env_count; i++)
    {
        if (strncmp(environ[i], name, strlen(name)) == 0 && environ[i][strlen(name)] == '=')
        {
            free(environ[i]);
            environ[i] = environ[env_count - 1];
            environ[env_count - 1] = NULL;
            char **new_environ = realloc(environ, (sizeof(char *) * env_count));
            if (new_environ == NULL)
                return -1;
            environ = new_environ;

            return 0;
        }
    }

    return 0;
}

int main(void)
{
    if (_unsetenv("MY_VAR") == 0)
        printf("MY_VAR unset successfully.\n");
    else
        printf("Failed to unset MY_VAR.\n");

    return 0;
}

