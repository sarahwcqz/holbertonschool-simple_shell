#include "simple_shell.h"

/**
 * _getenv - finds value of passed env variable
 * @name: env variable to find value of
 * Return: pointer to value string.
 */
char *_getenv(const char *name)
{
	size_t nbytes = 0, index = 0;

	nbytes = strlen(name);

	while (environ[index] != NULL)
	{
		if ((strncmp(environ[index], name, nbytes) == 0) &&
		(environ[index][nbytes] == '='))
		{
			return (environ[index] + nbytes + 1);
		}
		index++;
	}
	return (NULL);
}
