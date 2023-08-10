#include "main.h"

/**
 * main - Entry point of the program.
 * @argc: The argument count
 * @argv: the argument values
 * @envp: The env var
 *
 * Return: Always 0.
 */

int main(int argc, char *argv[], char **envp)
{
	char **env = envp;

	printf("Address of env (third parameter): %p\n", (void *)envp);
	printf("Address of environ (global variable): %p\n", (void *)env);

	return (0);
}
