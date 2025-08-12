#include "header.h"

int main(int ac, char **av)
{
	(void)ac;
	(void)av;

	char *argv[] = {"/bin/ls", "-l", "/tmp", NULL};
	extern char **environ;
	pid_t id, ppid, pid;
	int count = 0;

	while (count < 5)
	{
		id = fork();
		if (id == -1)
			return (-1);


		if (id != 0)
			wait(NULL);

		else if (id == 0)
		{
			ppid = getppid();
			pid = getpid();
			printf("parent : %u\n", ppid);
			printf("child : %u\n", pid);
			execve(argv[0], argv, environ);
		}
		count++;
	}


	return (0);
}
