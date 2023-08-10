#include "main.h"

/**
 * splitStringToArray - Splits a string into an array of words
 * @str: The input string
 * @delim: The delimiter to split the string by
 *
 * Return: Array of words or NULL on failure
 */
char **splitStringToArray(const char *str, const char *delim)
{
	char *s = strdup(str);

	if (strtok(s, delim) == 0)
		return (NULL);
	int nw = 1;

	while (strtok(NULL, delim) != 0)
		nw += 1;
	strcpy(s, str);
	char **v = malloc((nw + 1) * sizeof(char *));
	int i;

	v[0] = strdup(strtok(s, delim));
	for (i = 1; i != nw; ++i)
		v[i] = strdup(strtok(NULL, delim));
	v[i] = NULL;
	free(s);

	return (v);
}
