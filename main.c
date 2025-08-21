#include "simple_shell.h"

/**
 * main - entry point of this beautiful Shell
 * @argc: number of arguments
 * @argv: arguments given by user
 * Return: 0 on normal exit.
 */
int main (int argc, char *argv[])
{
	char *next = NULL, *cmd_line[128]; char *prgm_name = strdup(argv[0]);

	printf("Hi there!\n");
	while (1)
	{
		pid_t id = 0;
		int ret_arg = 0;
		char *buff = NULL;
		size_t index = 0, taille_buff = 0;

		(void)argc;
		printf("-> ");

		if (getline(&buff, &taille_buff, stdin) == -1)
			return (0);

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
			argv[0] = get_path(argv);

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
