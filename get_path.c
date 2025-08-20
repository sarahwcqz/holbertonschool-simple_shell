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
	char *chemin, *env_p, *token, *cp_env_p;
	size_t length;

	env_p = _getenv(name);
	cp_env_p = strdup(env_p);
	token = strtok(cp_env_p, ":");

	while (token != NULL)
	{
		length = strlen(token) + strlen(argv[0]) + 2;
		chemin = malloc(length);
		if (chemin == NULL)
			return (NULL);

		sprintf(chemin, "%s/%s", token, argv[0]);

		if (access(chemin, X_OK) == 0)
		{
			return (chemin);
		}
		free(chemin);
		token = strtok(NULL, ":");
	}
	return (NULL);
}
