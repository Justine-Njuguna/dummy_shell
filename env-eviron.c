#include "main.h"

/**
 * main - Access the env variables using environ var.
 * @argc: Number of CLI arguments.
 * @argv: An array of strings representing the cli arguments.
 * @envp: An array of strings representing the env variables.
 *
 * Return: Always 0.
 */

int main(int argc, char *argv[], char *envp[])
{
	int i;

	for (i = 0;  envp[i] != NULL; i++)
	{
		printf("Environment variable %d: %s\n", i, envp[i]);
	}

	return (0);
}
