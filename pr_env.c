#include "simple_shell.h"

/**
 * pr_env - implements the env built-in
 * Return: void
 *
 * Description :
 * Recreates the env built in of the sh, so that when 'env' is passed as a
 * command it prints the environement variables to the stdout.
 */
void pr_env(void)
{
	int idx_env = 0;

	while (environ[idx_env] != NULL)
	{
		printf("%s\n", environ[idx_env]);
		idx_env++;
	}
}
