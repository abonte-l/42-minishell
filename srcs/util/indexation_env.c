/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexation_env.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonte-l <abonte-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 11:41:55 by abonte-l          #+#    #+#             */
/*   Updated: 2022/04/02 13:02:48 by abonte-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	indexation_env(t_dlst *list)
{
	t_node *p_temp;
	int i;
	
	i = 0;
	if (list != NULL)
	{
		p_temp = list->head;
		while (p_temp != NULL)
		{
			p_temp->index = i;
			p_temp = p_temp->next;
			i++;
		}
	}
}
