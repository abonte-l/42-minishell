#include "../inc/libft.h"


t_dlst	*dlist_new(void)
{
	t_dlst *list;
	list = malloc(sizeof * list);
	if (list != NULL)
	{
		list->length = 0;
		list->head = NULL;
		list->tail = NULL;
	}
	return (list);
}

