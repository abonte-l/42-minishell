#include "../inc/libft.h"

t_dlst *dlist_add_middle(t_dlst *p_list, char *data, int position)
{
    if (p_list != NULL)
    {
        struct node *p_temp = p_list->p_head;
        int i = 1;
        while (p_temp != NULL && i <= position)
        {
            if (position == i)
            {
                if (p_temp->p_next == NULL)
                {
                    p_list = dlist_append(p_list, data);
                }
                else if (p_temp->p_prev == NULL)
                {
                    p_list = dlist_prepend(p_list, data);
                }
                else
                {
                    struct node *p_new = malloc(sizeof *p_new);;
                    if (p_new != NULL)
                    {
                        p_new->data = data;
                        p_temp->p_next->p_prev = p_new;
                        p_temp->p_prev->p_next = p_new;
                        p_new->p_prev = p_temp->p_prev;
                        p_new->p_next = p_temp;
                        p_list->length++;
                    }
                }
            }
            else
            {
                p_temp = p_temp->p_next;
            }
            i++;
        }
    }
    return p_list;
}