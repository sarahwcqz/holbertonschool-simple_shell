#include "simple_shell.h"

/**
 * get_path - finds directory in which
 * passed command has been found
 * @argv: arguments passed by user
 * @chemin: buffer to store path & command in
 * Return: pointer to correct path
 */
char *get_path(char **argv, char *chemin)
{
	const char *name = "PATH";
	char *env_p, *token, *cp_env_p;

	env_p = _getenv(name);
	cp_env_p = strdup(env_p);
	token = strtok(cp_env_p, ":");

	while (token != NULL)
	{
		sprintf(chemin, "%s/%s", token, argv[0]);

		if (access(chemin, X_OK) == 0)
		{
			free(cp_env_p);
			return (chemin);
		}
		token = strtok(NULL, ":");
	}
	free(cp_env_p);
	return (argv[0]);
}
