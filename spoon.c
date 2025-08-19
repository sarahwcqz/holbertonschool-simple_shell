#include "simple_shell.h"

/**
 * _fork - launches a fork
 * @id: used to communicate with the fork
 * @argv: argument passed by user
 * Return: id of child
 *
 * Description :
 * launches a fork process, tells to the parent process to wait for the child
 * process to finish, and to the child process to execute a command.
 */
int _fork(int id, char **argv, char *prgm_name)
{
	int status;
	char *prog_name = prgm_name;

	id = fork();
	if (id == -1)
	{
		perror("fork");
		return (-1);
	}
	if (id == 0)
	{
		if (execve(argv[0], argv, environ) == -1)
		{
			fprintf(stderr, "%s: 1: %s: not found\n", prog_name, argv[0]);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		if ((waitpid(id, &status, 0)) == -1)
		{
			perror("waitpid");
			return (-1);
		}
	}
	return (0);
}
