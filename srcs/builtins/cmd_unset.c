/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_unset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonte-l <abonte-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 18:43:12 by abonte-l          #+#    #+#             */
/*   Updated: 2022/04/02 12:19:46 by abonte-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	builtin_unset(char **built_in, t_dlst *list)
{
	t_node *tmp;

	if (list != NULL)
	{
		tmp = list->head;
		while (tmp != NULL)
		{
			if (!ft_strncmp(tmp->data, built_in[1], (ft_strlen(built_in[1])))) 
				dlist_delete_node(list,tmp->data);
			tmp = tmp->next;
		}
	}
}
