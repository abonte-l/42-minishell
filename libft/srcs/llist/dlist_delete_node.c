/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlist_delete_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonte-l <abonte-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 12:26:34 by abonte-l          #+#    #+#             */
/*   Updated: 2022/06/23 12:35:55 by abonte-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void	make_magic(t_dlst *list, t_node *p_temp)
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
}

t_dlst	*dlist_delete_node(t_dlst *list, char *data)
{
	int		found;
	t_node	*p_temp;

	p_temp = list->head;
	if (list != NULL)
	{
		found = 0;
		while (p_temp != NULL && !found)
		{
			if (p_temp->data == data)
			{
				make_magic(list, p_temp);
				free(p_temp);
				list->length--;
				found = 1;
			}
			else
			p_temp = p_temp->next;
		}
	}
	return (list);
}
