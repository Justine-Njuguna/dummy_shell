#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * print_prompt - Prints a shell prompt
 */
void print_prompt(void)
{
    printf("Aeldra_Shell$ ");
}

/**
 * execute_command - Executes a command using execve
 * @command: The command to execute
 */
void execute_command(char *command)
{
    char *argv[] = {command, NULL};
    char *envp[] = {NULL};

    if (execve(command, argv, envp) == -1)
    {
        perror("Error:");
        exit(1); // Exit the child process on error
    }
}

/**
 * main - Main function of the shell program
 *
 * Return: Always 0.
 */
int main(void)
{
    /* Shell logic */
    while (1)
    {
        print_prompt();

        // Read user input
        char input[100];
        fgets(input, sizeof(input), stdin);

        // Remove newline character from input
        if (input[strlen(input) - 1] == '\n')
        {
            input[strlen(input) - 1] = '\0';
        }

        // Parse and execute commands
        if (strcmp(input, "exit") == 0)
        {
            printf("Exiting the shell\n");
            break;
        }
        else
        {
            printf("Executing command: %s\n", input);

            // Fork a child process to execute the command
            pid_t child_pid = fork();
            if (child_pid == -1)
            {
                perror("Error:");
            }
            else if (child_pid == 0)
            {
                // Child process code
                execute_command(input);
            }
            else
            {
                // Parent process code
                wait(NULL); // Wait for the child process to complete
            }
        }

        // ...
    }
    return 0;
}

