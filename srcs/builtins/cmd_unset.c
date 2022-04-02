/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_unset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonte-l <abonte-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 18:43:12 by abonte-l          #+#    #+#             */
/*   Updated: 2022/04/01 18:45:44 by abonte-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	builtin_unset(char **built_in, t_dlst *p_list)
{
	if (p_list != NULL)
    {
        struct s_node *p_temp = p_list->head;
        while (p_temp != NULL)
        {
            if (!ft_strncmp(p_temp->data, built_in[1], 5)) 
			{
				path = ft_strdup(p_temp->data);
				return (path);
			}
		    p_temp = p_temp->next;
        }
    }
    return (path);
}
}
