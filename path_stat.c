#include "simple_shell.h"

/**
 * get_dir - finds directory in which
 * passed command has been found
 * @argv: arguments passed by user
 * Return: pointer to correct path
 */
char *get_dir(char **argv)
{
	const char *name = "PATH";
	char *end_note = argv[0];
	char *env_p, *token, *chemin;
	struct stat st;

	env_p = _getenv(name);
	printf("env_p is %s\n", env_p);
	token = strtok(env_p, ":");

	while (token != NULL)
	{
		printf("Token is %s\n", token);
		chemin = malloc(sizeof(char) * (strlen(token) + strlen(end_note) + 2));
		if (chemin == NULL)
		{
			printf("oopsie\n");
			return (NULL);
		}
		sprintf(chemin, "%s/%s", token, end_note);
		printf("%s\n", chemin);

		if (stat(chemin, &st) == 0)
		{
			/*int i = 1; while (argv[i] != NULL){}*/
			return (chemin);
		}
		token = strtok(NULL, ":");
	}
	printf("Couldn't find it :/\n");
	return (NULL);
}
