#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern char **environ;

/**
 * _setenv - Changes or adds an environment variable
 * @name: The name of the environment variable
 * @value: The value to set for the environment variable
 * @overwrite: Flag to indicate overwrite if the variable already exists
 * Return: 0 on success, -1 on failure
 */
int _setenv(const char *name, const char *value, int overwrite)
{
    if (name == NULL || name[0] == '\0' || strchr(name, '=') != NULL)
        return -1;

    size_t name_len = strlen(name);
    size_t value_len = strlen(value);

    int env_count = 0;
    while (environ[env_count] != NULL)
        env_count++;

    for (int i = 0; i < env_count; i++)
    {
        if (strncmp(environ[i], name, name_len) == 0 && environ[i][name_len] == '=')
        {
            if (!overwrite)
                return 0;

            char *new_var = malloc(name_len + value_len + 2);
            if (new_var == NULL)
                return -1;

            strcpy(new_var, name);
            strcat(new_var, "=");
            strcat(new_var, value);

            free(environ[i]);
            environ[i] = new_var;

            return 0;
        }
    }

    char *new_var = malloc(name_len + value_len + 2);
    if (new_var == NULL)
        return -1;

    strcpy(new_var, name);
    strcat(new_var, "=");
    strcat(new_var, value);

    char **new_environ = realloc(environ, (sizeof(char *) * (env_count + 2)));
    if (new_environ == NULL)
    {
        free(new_var);
        return -1;
    }

    environ = new_environ;
    environ[env_count] = new_var;
    environ[env_count + 1] = NULL;

    return 0;
}

int main(void)
{
    if (_setenv("MY_VAR", "Hello", 1) == 0)
        printf("MY_VAR set successfully.\n");
    else
        printf("Failed to set MY_VAR.\n");

    if (_setenv("MY_VAR", "World", 1) == 0)
        printf("MY_VAR updated successfully.\n");
    else
        printf("Failed to update MY_VAR.\n");

    if (_setenv("NEW_VAR", "New Value", 0) == 0)
        printf("NEW_VAR set successfully.\n");
    else
        printf("Failed to set NEW_VAR.\n");

    return 0;
}

