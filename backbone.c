#include "simple_shell.h"

/**
 * main - entry point
 * @argc: number of arguments
 * @argv: arguments given by user
 * @env: environment given as param
 * Return: always 0.
 */
int main(int argc, char *argv[], char **env)
{
	while (1)
	{
/* -------------------------- declaration ----------------------*/
		pid_t id = 0;
		int status;
		char *buff = NULL;
		(void)argc;
		(void)env;

/* ----------------------------prompt and stuff -----------------*/
		argv = setup(argv, buff);
		if (argv == NULL)
		{
			printf("bye bruh\n");
			return (0);
		}

/*  -------------------- on fork -------------------------- */
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
			if (execve(argv[0], argv, environ) == -1)
				printf("message d'erreur a definir, enter another cmd\n");

		}
		/* ----------si parent --------- */
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
