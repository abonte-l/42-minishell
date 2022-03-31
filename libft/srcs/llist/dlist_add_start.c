#include "../inc/libft.h"

t_dlst	*dlist_add_start(t_dlst *list, char *data)
{
	struct s_node	*new_node;

	new_node = NULL;
	if (list != NULL)
	{
		new_node = malloc(sizeof * new_node);
		new_node_start(list, new_node, data);

	}
	return (list);
}