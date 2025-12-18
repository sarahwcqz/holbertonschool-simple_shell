#include "header.h"

char *_getenv(const char *name)
{
	size_t /*i = 0,*/ nbytes = 0, index = 0;
	/*char *value;*/

	nbytes = strlen(name);

	while (environ[index] != NULL)
	{
		if ((strncmp(environ[index], name, nbytes) == 0) &&
		(environ[index][nbytes] == '='))
		{
			/*nbytes += 2;
			while (*environ[nbytes] != '\0')
			{
				value[i] = *environ[nbytes];
				i++;
				nbytes++;
			}
			value[i] = '\0';*/
			return (environ[index] + nbytes + 1);
		}
		index++;
	}
	return (NULL);
}


int main(void)
{
	char *ret = NULL, *name = "SHELL";

	ret = _getenv(name);
	printf("%s\n", ret);
	return (0);
}
