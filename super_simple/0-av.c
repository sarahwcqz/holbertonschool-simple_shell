#include "header.h"

int main(int ac, char **av)
{
	int i = 1;
	(void)ac;

	while (av[i] != NULL)
	{
		printf("%s ", av[i]);
		i++;
	}
	printf("\n");
	return (0);
}
