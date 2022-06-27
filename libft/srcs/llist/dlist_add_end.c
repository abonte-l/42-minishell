/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlist_add_end.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonte-l <abonte-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 12:15:50 by abonte-l          #+#    #+#             */
/*   Updated: 2022/06/23 12:17:10 by abonte-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

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
