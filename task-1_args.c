#include "main.h"

/**
 * main - Entry point.
 *
 * Return: Always 0.
 */

int main(void)
{
	char *input = NULL;
	size_t len = 0;

	while (1)
	{
		printf("$ ");

		if (getline(&input, &len, stdin) != -1)
		{
			printf("%s", input);
		}
		else
		{
			break;
		}
	}

	free(input);

	return (0);
}
