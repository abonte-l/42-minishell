/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   llst_create_dest.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonte-l <abonte-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 11:57:22 by abonte-l          #+#    #+#             */
/*   Updated: 2022/03/27 09:49:03 by abonte-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

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