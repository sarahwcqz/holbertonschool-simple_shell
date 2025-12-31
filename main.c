#include "simple_shell.h"

/**
 * main - entry point of this beautiful Shell
 * @argc: number of arguments
 * @argv: arguments given by user
 * Return: 0 on normal exit.
 */
int main (int argc, char *argv[])
{
	char *next = NULL, chemin[1024], *cmd_line[128]; char *prgm_name = strdup(argv[0]);
	/* next : for strtok   chemin : chemin d'exe	cmd_line : tableau d'argmt	prgm_name : nom du prgm */

	/* si mode interactif */
	if (isatty(STDIN_FILENO))
		printf("Hi there!\n");

	/* boucle infinie */
	while (1)
	{
		/* reinit des var */
		pid_t id = 0;
		int ret_arg = 0;
		char *buff = NULL;
		size_t index = 0, taille_buff = 0;

		/* si mode interactif */
		(void)argc;
		if (isatty(STDIN_FILENO))
			printf("-> ");

		/* si EOF, exit */
		if (getline(&buff, &taille_buff, stdin) == -1)
		{
			free(prgm_name);
			free(buff);
			return (0);
		}

		/* tokenisation */
		next = strtok(buff, " \t\n");
		if (next == NULL)
		{
			cmd_line[0] = NULL;
		}
		while (next != NULL)
		{
			cmd_line[index] = next;
			index++;
			next = strtok(NULL, " \t\n");
		}
		cmd_line[index] = NULL;
		argv = cmd_line;


		ret_arg = checkarg(argv);
		if (ret_arg == 0)
		{
			free(buff);
			free(prgm_name);
			return (0);
		}
		if (ret_arg == 2)
		{
			free(buff);
			continue;
		}
		if (ret_arg == 3)
			argv[0] = get_path(argv, chemin);

		id = _fork(id, argv, prgm_name);
		if (id == -1)
		{
			perror("_fork");
			free(buff);
			free(prgm_name);
			return (-1);
		}
		free(buff);
	}
	return (0);
}
