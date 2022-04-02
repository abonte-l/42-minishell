#include "../inc/libft.h"

void dlist_delete(t_dlst **list)
{
    if (*list != NULL)
    {
		struct s_node *pos_tmp;
		struct s_node *pos_del;
		
        pos_tmp = (*list)->head;
        while (pos_tmp != NULL)
        {
            pos_del = pos_tmp;
            pos_tmp = pos_tmp->next;
            free(pos_del);
        }
        free(*list);
		*list = NULL;
    }
}