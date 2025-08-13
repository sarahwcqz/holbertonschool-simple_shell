#include "header.h"

int main(int argc, char *argv[])
{
	while (1)
	{	/* -------declaration------- */
		pid_t id;
		char *buff = NULL, *next;
		int status, truc;

		size_t i = 0, n = 0;
		(void)argc;
		printf("$ ");
		if (getline(&buff, &n, stdin) == -1)
		{
			free(buff);
			return (0);
		}

		next = strtok(buff, " \t\n");
		while (next != NULL)
		{
			argv[i] = next;
			i++;
			next = strtok(NULL, " \t\n");
		}
		id = fork();
		if (id == -1)
		{
			perror("fork");
			free(buff);
			return (-1);
		}
		/* --------- si on est dans le child ------ */
		if (id == 0)
		{
			execve(argv[0], argv, environ);
		}
		/* ----------si parent --------- */
		else
		{
			truc = waitpid(id, &status, 0);
			if (truc == -1)
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
