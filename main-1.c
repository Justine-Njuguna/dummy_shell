#include "main.h"

/**
 * main - Executes.
 *
 * Return: Always 0.
 */

int main(void)
{
	char input[] = "This is a test string";
	const char delimeter[] = " ";
	int i;

	char **wordArray = splitStringToArray(input, delimeter);

	if (wordArray != NULL)
	{
		for (i = 0; wordArray[i] != NULL; i++)
		{
			printf("Word %d: %s\n", i + 1, wordArray[i]);
		}
		for (i = 0; wordArray[i] != NULL; i++)
		{
			free(wordArray[i]);
		}
		free(wordArray);
	}

	return (0);
}
