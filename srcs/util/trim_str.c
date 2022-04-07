/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonte-l <abonte-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 14:41:10 by abonte-l          #+#    #+#             */
/*   Updated: 2022/04/05 14:43:40 by abonte-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

char	*trim_str(char *str, int i)
{
	char	*new_str;
	int 	j;
	int		k;
	
	j = 0;
	k = 0;
	new_str = NULL;
	j = (ft_strlen(str)) - i;
	new_str = malloc(sizeof(char) * (j + 1));
	while (k <= j)
	{
		new_str[k] = str[i];
		k++;
		i++;
	}	
	return (new_str);
	
}