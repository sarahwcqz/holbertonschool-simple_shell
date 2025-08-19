#include "simple_shell.h"

/**
 * get_path - 
 * 
 * Return:	the path to the exe of the command passed to the main,
 *			NULL if not found.
 */
char *get_path()
{
	const char *name = "PATH";
	char *env_p = getenv(name);
	char *token = NULL, *temp, *head;

	token = strtok(env_p, ":");

	while (token != NULL)
	{
		/* creation de la linked list ici ?*/
		token = strtok(NULL, ":");
	}

	while (temp != NULL)
	{
		if (temp->value == argv)
		{
			return (temp->value);
		}
		temp = temp->next;
	}

	return (NULL);

}
