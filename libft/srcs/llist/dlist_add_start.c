/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlist_add_start.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonte-l <abonte-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 12:15:53 by abonte-l          #+#    #+#             */
/*   Updated: 2022/06/23 12:20:46 by abonte-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

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
