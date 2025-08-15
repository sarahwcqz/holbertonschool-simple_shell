#include "header.h"

/**
 * main - entry point
 * @argc: number of arguments
 * @argv: arguments given by user
 * Return: always 0.
 */
int main(int argc, char *argv[])
{
	while (1)
	{
		pid_t id;
		int status;
		char *buff = NULL;
		(void)argc;

		setup(argv, buff);

		id = fork();
		if (id == -1)
		{
			perror("fork");
			free(buff);
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
				free(buff);
				return (-1);
			}
			free(buff);
		}
	}
	return (0);
}
