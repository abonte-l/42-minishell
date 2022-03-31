#include "../inc/libft.h"

t_dlst	*dlist_add_end(t_dlst *list, char *data)
{
	t_node	*new_node;

	if (list != NULL)
	{
		new_node = malloc(sizeof * new_node);
		new_node_end(list, new_node, data);
	}
	return (list);
}