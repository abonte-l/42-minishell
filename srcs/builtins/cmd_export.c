/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_export.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonte-l <abonte-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 12:14:16 by abonte-l          #+#    #+#             */
/*   Updated: 2022/04/02 12:55:21 by abonte-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	builtin_export(char **built_in, t_dlst *list)
{
	char	*tmp;
	int		i;
	int		iz_valid;

	tmp = ft_strdup(built_in[1]);
	i = 0;
	iz_valid = FALSE;
	while (tmp[i])
	{
		if (tmp[i] == EQUAL)
			iz_valid = TRUE;
		i++;
	}
	if (iz_valid == TRUE)
		dlist_add_end(list, tmp);
	else
		return;
}
