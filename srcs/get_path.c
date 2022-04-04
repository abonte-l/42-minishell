/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonte-l <abonte-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 16:35:58 by abonte-l          #+#    #+#             */
/*   Updated: 2022/04/04 18:07:15 by abonte-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

/* ************************************************************************** */
/*                            GET PATH FUNCTION                               */
/*                                                                            */
/* in get_path:                                                               */
/* lines 74-75 : If the path is null, a path is created                       */
/* lines 76-77 : If cmd is not the absolute path, we look for the absolute    */
/*               path of the binary with the PATH environment variable        */
/*                                                                            */
/* in make_magic_path:                                                        */
/* line 45     : Spliting the path to check where the binary is               */
/* lines 48-65 : Loop on each directory of the path to find the location      */
/*               of the binary                                                */
/* lines 50-51 : Allocation path's len + '/' + binary's len + 1 (\0)          */
/* lines 54-56 : Concatenation of the path, '/' and binary name               */
/* line 57     : Checking the existence of the file and we exiting the        */
/*               loop if access returns '0'                                   */
/* lines 64-65 : The binary is replaced by the absolute path or NULL if the   */
/*               binary does not exist                                        */
/*                                                                            */
/* ************************************************************************** */

char	*make_magic_path(char ** cmd, char *bin, char **path_split)
{
	int 	i;
	
	i = 0;
	while (path_split[i]) 
	{
		bin = (char *)ft_calloc(sizeof(char),
		(strlen(path_split[i]) + 1 + strlen(cmd[0]) + 1));
		if (bin == NULL)
			break;
		ft_strcat(bin, path_split[i]);
		ft_strcat(bin, "/");
		ft_strcat(bin, cmd[0]);
		if (access(bin, F_OK) == 0)
			break ;
		free(bin);
		bin = NULL;
		i++;
	}
	free_array(path_split);
	free(cmd[0]);
	cmd[0] = bin;
	return (bin);
}

bool	get_path(char **cmd, t_dlst *list)
{
	char	*path;
	char	*bin;
	char	**path_split;
	
	path = NULL;
	bin = NULL;
	path_split = NULL;
	if (cmd[0][0] != '/' && ft_strncmp(cmd[0], "./", 2) != 0)
	{
		path = env_2_path(list, path);
		if (path == NULL)
			return (false);
		path_split = split(path, ":");
		free(path);
		path = NULL;
		bin = make_magic_path(cmd, bin, path_split);
	}
	if (bin == NULL)
		return (false);
	else
		return (true);
}