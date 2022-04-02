#include "../inc/libft.h"

t_dlst *dlist_delete_node(t_dlst *list, char *data)
{
    t_node *p_temp;

    p_temp = list->head;
    if (list != NULL)
    {
        
        int found = 0;
        while (p_temp != NULL && !found)
        {
            if (p_temp->data == data)
            {
                if (p_temp->next == NULL)
                {
                    list->tail = p_temp->prev;
                    list->tail->next = NULL;
                }
                else if (p_temp->prev == NULL)
                {
                    list->head = p_temp->next;
                    list->head->prev = NULL;
                }
                else
                {
                    p_temp->next->prev = p_temp->prev;
                    p_temp->prev->next = p_temp->next;
                }
                free(p_temp);
                list->length--;
                found = 1;
            }
            else
            {
                p_temp = p_temp->next;
            }
        }
    }
    return list;
}