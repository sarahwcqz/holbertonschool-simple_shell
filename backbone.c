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
		pid_t id = 0;
		char *buff = NULL;
		(void)argc;

		argv = setup(argv, buff);
		id = _fork(id, argv);

		/* valgrind fail: 'address is on thread 1's stack' */
		free(buff);
		free(argv);
		/* & default termin process by 'read', 'setup', 'main'*/
	}
	return (0);
}
