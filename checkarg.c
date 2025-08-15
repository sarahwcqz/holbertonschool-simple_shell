#include "simple_shell.h"


int checkarg(char **argv)
{
		if (argv == NULL)				/* alors en vrai si on ne met pas de message d'adieu on gagne */
		{								/* 3 lignes, si besoin on peut les enlever mais je trouvais ca rigolo d'en mettre un*/
			printf("\nbye bruh\n");
			return (0);
		}
		if (strcmp(*argv, "exit") == 0)
		{
			printf("exit msg\n");
			return (0);
		}
	return (1);
}
