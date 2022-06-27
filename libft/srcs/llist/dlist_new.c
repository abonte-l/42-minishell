/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlist_new.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonte-l <abonte-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 12:26:18 by abonte-l          #+#    #+#             */
/*   Updated: 2022/06/23 12:36:33 by abonte-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

t_dlst	*dlist_new(void)
{
	t_dlst	*list;

	list = malloc(sizeof * list);
	if (list != NULL)
	{
		list->length = 0;
		list->head = NULL;
		list->tail = NULL;
	}
	return (list);
}
