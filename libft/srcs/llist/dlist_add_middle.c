#include "../inc/libft.h"

t_dlst *dlist_add_middle(t_dlst *list, char *data, int position)
{
    if (list != NULL)
    {
        t_node  *p_temp;
        t_node  *new_node;

        p_temp = list->head;
        int i = 1;
        while (p_temp != NULL && i <= position)
        {
            if (position == i)
            {
                if (p_temp->next == NULL)
                {
                    list = dlist_add_end(list, data);
                }
                else if (p_temp->prev == NULL)
                {
                    list = dlist_add_start(list, data);
                }
                else
                {
                    new_node = malloc(sizeof *new_node);;
                    if (new_node != NULL)
                    {
                        new_node->data = data;
                        p_temp->next->prev = new_node;
                        p_temp->prev->next = new_node;
                        new_node->prev = p_temp->prev;
                        new_node->next = p_temp;
                        list->length++;
                    }
                }
            }
            else
            {
                p_temp = p_temp->next;
            }
            i++;
        }
    }
    return list;
}