#include "header.h"

int main(int ac, char **av)
{
	char *line = NULL;
	size_t n = 0;

	(void)ac;
	(void)av;
	printf("$");
	getline(&line, &n, stdin);
	printf("%s", line);
	free(line);

	return (0);
}
