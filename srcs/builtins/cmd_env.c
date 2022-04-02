/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonte-l <abonte-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 14:56:30 by abonte-l          #+#    #+#             */
/*   Updated: 2022/04/02 13:01:57 by abonte-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	builtin_env(t_dlst *p_list)
{ 
	t_node *p_temp;

   
	if (p_list != NULL)
	{ 
		p_temp = p_list->head;
		while (p_temp != NULL)
		{
			printf("%s\n", p_temp->data);
			p_temp = p_temp->next;
		}
	}
}
