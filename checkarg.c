#include "simple_shell.h"


int checkarg(char **argv)
{
		if (argv == NULL)
		{
			printf("\nbye bruh\n");
			return (0);
		}
		if (argv[0] == NULL)
			return (2);
		if (strcmp(*argv, "exit") == 0)
		{
			printf("exit msg\n");
			return (0);
		}
		return (1);
}
