/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlist_display.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonte-l <abonte-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 12:26:28 by abonte-l          #+#    #+#             */
/*   Updated: 2022/06/23 13:44:45 by abonte-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void	dlist_display(t_dlst *p_list)
{
	struct s_node	*p_temp;

	p_temp = p_list->head;
	if (p_list != NULL)
	{
		while (p_temp != NULL)
		{
			printf("%s -> \n", p_temp->data);
			fflush(stdout);
			p_temp = p_temp->next;
		}
	}
	printf("NULL\n");
}
