#include "header.h"

int main(int ac, char **av, char **env)
{
	(void)ac;
	(void)av;

	printf("add de environ : %p\n", *environ);
	printf("add de env : %p\n", *env);

	return (0);
}
