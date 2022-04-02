#include "../inc/libft.h"

t_dlst *dlist_delete_node(t_dlst *list, char *data)
{
    if (list != NULL)
    {
        struct node *p_temp = list->p_head;
        int found = 0;
        while (p_temp != NULL && !found)
        {
            if (p_temp->data == data)
            {
                if (p_temp->p_next == NULL)
                {
                    list->p_tail = p_temp->p_prev;
                    list->p_tail->p_next = NULL;
                }
                else if (p_temp->p_prev == NULL)
                {
                    list->p_head = p_temp->p_next;
                    list->p_head->p_prev = NULL;
                }
                else
                {
                    p_temp->p_next->p_prev = p_temp->p_prev;
                    p_temp->p_prev->p_next = p_temp->p_next;
                }
                free(p_temp);
                list->length--;
                found = 1;
            }
            else
            {
                p_temp = p_temp->p_next;
            }
        }
    }
    return list;
}