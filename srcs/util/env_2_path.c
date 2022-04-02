/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_2_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonte-l <abonte-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 15:21:55 by abonte-l          #+#    #+#             */
/*   Updated: 2022/04/02 13:01:34 by abonte-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

char	*env_2_path(t_dlst *p_list, char *path)
{
	if (p_list != NULL)
	{
		struct s_node *p_temp = p_list->head;
		while (p_temp != NULL)
		{
			if (!ft_strncmp(p_temp->data, "PATH=", 5)) 
			{
				path = ft_strdup(p_temp->data);
				return (path);
			}
			p_temp = p_temp->next;
		}
	}
	return (path);
}