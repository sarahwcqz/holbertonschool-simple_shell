#include "header.h"

/**
 * main - entry point
 * @argc: number of arguments
 * @argv: user-provided arguments
 * Return: always 0.
 */
int main(int argc, char **argv)
{
	while (1)
	{
		struct stat stbuff;
		char *token, *buffer = NULL, *cmd = "_which";
		size_t idx = 0, i = 1, n = 0;
		(void)argc;

		printf("$ ");
		if (getline(&buffer, &n, stdin) == -1)
		{
			free(buffer);
			return (0);
		}

		token = strtok(buffer, " \t\n");
		while (token != NULL)
		{
			argv[idx] = token;
			idx++;
			token = strtok(NULL, " \t\n");
		}
		argv[idx] = NULL;
		if ((strcmp(argv[0], cmd)) == 0)
		{
			while (argv[i] != NULL)
			{
				if (stat(argv[i], &stbuff) == 0)
					printf("%s: FOUND\n", argv[i]);
				else
					printf("%s: NOT FOUND\n", argv[i]);

				i++;
			}
		}
	}
	return (0);
}
