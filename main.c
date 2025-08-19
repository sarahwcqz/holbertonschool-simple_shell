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
	printf("prompt\n");
	while (1)
	{
/* -------------------------- declaration ----------------------*/
		pid_t id = 0;
		int ret_arg;
		char *buff = NULL, *prgm_name = argv[0];
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

		id = _fork(id, argv, prgm_name);
	/* id va etre ecrase par fork, vraiment utile ce id ?*/
	/* gestion d'erreur si fork echoue ?*/
		free(buff);
	}
	return (0);
}
