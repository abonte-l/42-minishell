/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iz_special_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonte-l <abonte-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 15:32:50 by abonte-l          #+#    #+#             */
/*   Updated: 2022/06/27 20:05:57 by abonte-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

char	*dup_var(char *str, t_dlst *list)
{
	t_node	*tmp;
	int i = 0;

	while (ft_izalnum(str[i]) == 0)
		i++;
	str = trim_str(str, i);
	i = 0;
	while (ft_izalnum(str[i]) == 1)
		i++;
	str = ft_strndup(str, i);
	ft_strcat(str, "=");
	if (list != NULL)
	{
		tmp = list->head;
		while (tmp != NULL)
		{
			if (!ft_strncmp(tmp->data, str, (ft_strlen(str))))
			{
				ft_strcpy(str, &tmp->data[ft_strlen(str)]);
				return (str);
			}	
			tmp = tmp->next;
		}
	}
	return (NULL);
}

char	**iz_special_char(t_dlst *list, char **cmd)
{
	int i = 0, j = 0;

	while (cmd[i])
	{
	j = 0;
		while (cmd[i][j])
		{
			if (cmd[i][j] == VAR && cmd[i][j + 1] != TAG)
			{
				cmd[i] = ft_strdup(dup_var(cmd[i], list));
				break;
			}
				
			j++;
		}
		i++;
	}
	return (cmd);	
}