#include "header.h"

int main(void)
{
	/* -------declaration------- */
	pid_t id;
	char *buff = NULL, *argv[2];
	size_t n = 0;
	extern char **environ;

	printf("$ ");

	getline(&buff, &n, stdin);
	buff[strcspn(buff, "\n")] = '\0';
	printf("getline ok\n");

	id = fork();
	if (id == -1)
	{
		free(buff);
		return (-1);
	}

	/* --------- si on est dans le child ------ */
	if (id == 0)
	{
		printf("C on a fork trql dans child\n");
		argv[0] = buff;
		argv[1] = NULL;
		printf("argv0 = %s\n", argv[0]);
		printf("argv1 = %s\n", argv[1]);
		printf("buff = %s\n", buff);
		execve(buff, argv, environ);
		perror("execve");
		printf("C on exe oklm\n");
	}

	/* ----------si parent --------- */
	else if (id != 0)
	{
		printf("P on est dans parent\n");
		wait(NULL);
		printf("P on wait in peace\n");
	}

	free(buff);
	printf("C + P on a free le badboy buffer\n");

	return (0);
}
