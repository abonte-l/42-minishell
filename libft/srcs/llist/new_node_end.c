#include "../inc/libft.h"

void	new_node_end(t_dlst *list, t_node *new_node, char *data)
{
	if (new_node != NULL)
	{
		new_node->data = data;
		new_node->next = NULL;
		if (list->tail == NULL)
		{
			new_node->prev = NULL;
			list->head = new_node;
			list->tail = new_node;
		}
		else
		{
			list->tail->next = new_node;
			new_node->prev = list->tail;
			list->tail = new_node;
		}
		list->length++;
	}
}
