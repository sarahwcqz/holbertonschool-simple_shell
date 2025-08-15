#include "simple_shell.h"

/**
 * _fork - launches a fork
 * @id: used to communicate with the fork
 * @argv: argument passed by user
 * Return: id of child
 */
int _fork(int id, char **argv)
{
	int status;

	id = fork();
	if (id == -1)
	{
		perror("fork");
		return (-1);
	}
	if (id == 0)
	{
		execve(argv[0], argv, environ);
	}
	else
	{
		if ((waitpid(id, &status, 0)) == -1)
		{
			perror("waitpid");
			return (-1);
		}
	}
	return (id);
}
