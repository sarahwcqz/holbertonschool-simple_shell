#include "simple_shell.h"

/**
 * checkarg - analyzes the first argument passed to the program
 * @argv: pointer to an array of strings representing command-line arguments
 * Return:	0 if the main needs to be shut,
 *			2 if the rest of the main needs to be skipped,
 *			1 otherwise.
 */
int checkarg(char **argv)
{
		if (argv == NULL)
		{
			printf("\nbye!\n");
			return (0);
		}

		if (argv[0] == NULL)
			return (2);

		if (argv[0][0] != '/')
		{
			if (strcmp(*argv, "exit") == 0)
			{
				printf("Hope to see you soon!\n");
				return (0);
			}

			else if (strcmp(*argv, "env") == 0)
			{
				pr_env();
				return (2);
			}
			else
				return (3);
		}
		return (1);
}
