#include "simple_shell.h"

/**
 * main - entry point of this beautiful Shell
 * @argc: number of arguments
 * @argv: arguments given by user
 * Return: 0 on normal exit.
 *
 * Description :
 * This minimal shell runs in an infinite loop, displaying a prompt to the
 * user, reading a command line, tokenizing it into arguments, and executing
 * the corresponding command using fork + execve. It handles built-in commands
 * like "exit" and "env", ignores empty lines, and properly frees memory at
 * each iteration.
 */
int main(int argc, char *argv[])
{
	char *prgm_name = strdup(argv[0]);

	printf("prompt one time\n");
	while (1)
	{
/* -------------------------- declaration ----------------------*/
		pid_t id = 0;
		int ret_arg;
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
		if (ret_arg == 3)
			argv[0] = get_dir(argv);

		id = _fork(id, argv, prgm_name);
		if (id == -1)
		{
			perror("_fork");
			return (-1);
		}

		free(buff);
	}
	return (0);
}
