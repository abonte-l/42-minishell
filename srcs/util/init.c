/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonte-l <abonte-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 14:55:42 by abonte-l          #+#    #+#             */
/*   Updated: 2022/04/05 15:19:45 by abonte-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	init_export(char **built_in, t_export *export)
{
	export->iz_valid = FALSE;
	export->tmp = ft_strdup(built_in[1]);
	export->tmp_2 = NULL;
	export->i = 0;
	
}

