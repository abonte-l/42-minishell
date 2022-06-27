/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_node_start.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonte-l <abonte-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 12:16:28 by abonte-l          #+#    #+#             */
/*   Updated: 2022/06/23 12:16:33 by abonte-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void	new_node_start(t_dlst *list, t_node *new_node, char *data)
{
	if (new_node != NULL)
	{
		new_node->data = data;
		new_node->prev = NULL;
		if (list->tail == NULL)
		{
			new_node->next = NULL;
			list->head = new_node;
			list->tail = new_node;
		}
		else
		{
			list->head->prev = new_node;
			new_node->next = list->head;
			list->head = new_node;
		}
		list->length++;
	}
}
