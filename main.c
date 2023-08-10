#include "main.h"

/**
 * main - exec
 *
 * Return: 0 else 1.
 */

int main(void)
{
	pid_t child_pid;
	int status, i;

	for (i = 0; i < 5; i++)
	{
		child_pid = fork();

		if (child_pid == -1)
		{
			perror("Error: ");
			return (1);
		}

		if (child_pid == 0)
		{
			execl("/bin/ls", "ls", "-l", "/tmp", NULL);
			perror("Error: ");
			return (1);
		}
		else
		{
			wait(&status);
		}
	}

	return (0);
}
