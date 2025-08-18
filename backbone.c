#include "simple_shell.h"

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
/* -------------------------- declaration ----------------------*/
		pid_t id = 0;
		int /*status*/ret_arg;
		char *buff = NULL;
		(void)argc;
/* ----------------------------prompt and stuff -----------------*/
		argv = setup(argv, &buff);
		ret_arg = checkarg(argv);
		if (ret_arg == 0)
		{
			free(buff);
			return (0);
		}
		if (ret_arg == 2)
		{
			free(buff);
			continue;
		}
		id = _fork(id, argv);
		free(buff);
	}
	return (0);
}
