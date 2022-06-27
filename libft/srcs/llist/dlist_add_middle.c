/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlist_add_middle.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonte-l <abonte-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 12:15:44 by abonte-l          #+#    #+#             */
/*   Updated: 2022/06/23 13:45:22 by abonte-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void	make_magic(t_node *new_node, char *data, t_node *p_temp, t_dlst *list)
{
	new_node = malloc(sizeof * new_node);
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

t_dlst	*dlist_add_middle(t_dlst *list, char *data, int position)
{
	int		i;
	t_node	*p_temp;
	t_node	*new_node;

	new_node = NULL;
	if (list != NULL)
	{
		p_temp = list->head;
		i = 1;
		while (p_temp != NULL && i <= position)
		{
			if (position == i)
			{
				if (p_temp->next == NULL)
					list = dlist_add_end(list, data);
				else if (p_temp->prev == NULL)
					list = dlist_add_start(list, data);
				else
					make_magic(new_node, data, p_temp, list);
			}
			else
				p_temp = p_temp->next;
			i++;
		}
	}
	return (list);
}
