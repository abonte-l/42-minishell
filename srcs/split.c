/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonte-l <abonte-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 09:10:47 by abonte-l          #+#    #+#             */
/*   Updated: 2022/06/23 16:30:45 by abonte-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

/* ************************************************************************** */
/*                              SPLIT FUNCTION                                */
/*                                                                            */
/*  lines 34-41 : Split the string on delimiter, put every token              */
/*              in an array                                                   */
/*  lines 42-43 : Allocation of an element set to NULL at the end             */
/*              of the array                                                  */
/*                                                                            */
/* ************************************************************************** */

void	make_magic_split(char **cmd, size_t idx)
{
	cmd[idx] = NULL;
	free_array(cmd);
}

char	**split(char *raw_data, char *limit)
{
	char	*ptr;
	char	**cmd;
	size_t	idx;
	size_t	n;

	ptr = NULL;
	cmd = NULL;
	idx = 0;
	n = 0;
	while (n < ft_strlen(raw_data))
	{
		ptr = ft_strtok(raw_data + n, limit);
		if (!ptr)
		{
			make_magic_split(cmd, idx);
			return (NULL);
		}
		cmd = (char **)ft_realloc(cmd, ((idx + 1) * sizeof(char *)));
		cmd[idx] = ptr;
		n += ft_strlen(ptr) + 1;
		++idx;
	}
	cmd = (char **)ft_realloc(cmd, ((idx + 1) * sizeof(char *)));
	cmd[idx] = NULL;
	return (cmd);
}
