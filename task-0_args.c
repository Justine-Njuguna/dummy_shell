#include "main.h"

/**
 * main - Entry point.
 * @ac: Argument count.
 * @av: Argument vector.
 *
 * Return: Always 0.
 */

int main(int ac, char **av)
{
	char **arg = av;

	while (*arg != NULL)
	{
		printf("%s\n", *arg);
		arg++;
	}

	return (0);
}
