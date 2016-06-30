#include "list.h"
#include <stdlib.h>

int add_end_dcl_list(List **, char *);

/* convert an array of strings to a circular linked list */
List *array_to_dcl_list(char **array)
{
	List *list;
	int i;

	list = NULL;

	for (i = 0; array[i] != NULL; i++)
	{
		if (add_end_dcl_list(&list, array[i]) == 1)
		{
			return NULL;
		}
	}

	return list;
}
