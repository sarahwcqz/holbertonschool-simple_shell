#include "header.h"

/**
 * main - entry point
 * Return: always 0.
 */
int main(void)
{
	const char *name = "PATH";
	char *env_p = getenv(name);
	char *next = NULL;

	next = strtok(env_p, ":");

	while (next != NULL)
	{
		printf("%s", next);
		next = strtok(NULL, ":");
		if (next != NULL)
			printf("\n");
	}
	return (0);
}
