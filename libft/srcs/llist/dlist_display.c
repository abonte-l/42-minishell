#include "../inc/libft.h"

void dlist_display(t_dlst *p_list)
{
    if (p_list != NULL)
    {
        struct s_node *p_temp = p_list->head;
        while (p_temp != NULL)
        {
            printf("%s -> \n", p_temp->data);
            fflush(stdout);
            p_temp = p_temp->next;
        }
    }
    printf("NULL\n");
}