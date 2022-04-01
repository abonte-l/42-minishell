/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonte-l <abonte-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 09:10:47 by abonte-l          #+#    #+#             */
/*   Updated: 2022/04/01 11:38:28 by abonte-l         ###   ########.fr       */
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

char **split(char *raw_data, char *limit)
{
	char	*ptr;
	char	**cmd;
	size_t	idx;

	ptr = NULL;
	cmd = NULL;
	idx = 0;
	ptr = ft_strtok(raw_data, limit);
	while (ptr) 
	{
		cmd = (char **)ft_realloc(cmd, ((idx + 1) * sizeof(char *)));
		cmd[idx] = ft_strdup(ptr);
		ptr = ft_strtok(NULL, limit);
		++idx;
	}
	cmd = (char **)ft_realloc(cmd, ((idx + 1) * sizeof(char *)));
	cmd[idx] = NULL;
	return (cmd);
}

