/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_export.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonte-l <abonte-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 12:14:16 by abonte-l          #+#    #+#             */
/*   Updated: 2022/04/05 15:41:41 by abonte-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	make_magic_export(char *str_var, char *str, t_dlst *list)
{
	t_node	*tmp;

	if (list != NULL)
	{
		tmp = list->head;
		while (tmp != NULL)
		{
			if (!ft_strncmp(tmp->data, str, (ft_strlen(str))))
				ft_strcat(tmp->data, str_var);	
			tmp = tmp->next;
		}
	}
}

int	check_izvalid(char *tmp, int i)
{
	while (tmp[i])
	{
		if (tmp[i] == EQUAL)
			return (TRUE);
		i++;
	}
	return (FALSE);
}

void	get_var_name(char *tmp, char *tmp_2)
{
	int	i;

	i = 0;
	while (tmp[i] != EQUAL)
		i++;
	tmp_2 = ft_strncpy(tmp_2, tmp, i);
}

void	builtin_export(char **built_in, t_dlst *list)
{
	t_export	*export;

	export = NULL;
	init_export(built_in, export);
	export->iz_valid = check_izvalid(export->tmp, export->i);
	if (export->iz_valid == TRUE)
	{
		get_var_name(export->tmp, export->tmp_2);
		export->tmp = trim_str(export->tmp, export->i);
		export->i = ft_strlen(export->tmp_2) - 2;
		if (export->tmp_2[export->i] == PLUS)
			make_magic_export(export->tmp, export->tmp_2, list);
		else
			dlist_add_end(list, export->tmp);
	}
	else
		return;
}
