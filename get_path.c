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
	char *chemin, *env_p, *token;

	size_t length = 0;

	env_p = _getenv(name);
	token = strtok(env_p, ":");

	while (token != NULL)
	{
		length = strlen(token) + strlen(argv[0]) + 2;
		chemin = malloc(sizeof(char) * length);
		if (chemin == NULL)
			return (NULL);
		sprintf(chemin, "%s", token);

		if (access(chemin, F_OK) == 0)
		{
			return (chemin);
		}
		token = strtok(NULL, ":");
	}
	return (NULL);
}

/**
 * get_path - adds our command at the end
 * @argv: argument containing cmd
 * Return: pointer to full path.
 */
char *get_path(char **argv)
{
	char *cmd_path, *end_note;

	cmd_path = get_dir(argv);
	if (cmd_path == NULL)
		return (NULL);

	end_note = argv[0];

	sprintf(cmd_path + strlen(cmd_path), "/%s", end_note);
	return (cmd_path);
}
