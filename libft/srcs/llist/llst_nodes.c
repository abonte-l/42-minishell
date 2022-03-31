/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   llst_utils_02.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonte-l <abonte-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 15:20:32 by abonte-l          #+#    #+#             */
/*   Updated: 2022/03/25 14:55:11 by abonte-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

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

void	new_node_end(t_dlst *list, t_node *new_node, char *data)
{
	if (new_node != NULL)
	{
		new_node->data = data;
		new_node->next = NULL;
		if (list->tail == NULL)
		{
			new_node->prev = NULL;
			list->head = new_node;
			list->tail = new_node;
		}
		else
		{
			list->tail->next = new_node;
			new_node->prev = list->tail;
			list->tail = new_node;
		}
		list->length++;
	}
}
