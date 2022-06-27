/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlist_delete_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonte-l <abonte-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 12:16:17 by abonte-l          #+#    #+#             */
/*   Updated: 2022/06/23 12:39:20 by abonte-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void	dlist_delete(t_dlst **list)
{
	struct s_node	*pos_tmp;
	struct s_node	*pos_del;

	if (*list != NULL)
	{
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
