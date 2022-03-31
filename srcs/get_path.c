/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonte-l <abonte-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 16:35:58 by abonte-l          #+#    #+#             */
/*   Updated: 2022/03/31 14:59:53 by abonte-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

/* ************************************************************************** */
/*                            GET PATH FUNCTION                               */
/*                                                                            */
/* in get_path:      				                                          */
/* lines 106-107 : If the path is null, a path is created                     */
/* lines 109-110 : If cmd is not the absolute path, we look for the absolute  */
/*				 path of the binary with the PATH environment variable        */
/*                                                                            */
/* in make_magic_path:      		                                          */
/* line 75 	   : Spliting the path to check where the binary is               */
/* lines 78-95 : Loop on each directory of the path to find the location      */
/*				of the binary 											      */
/* lines 80-81 : Allocation path's len + '/' + binary's len + 1 (\0)          */
/* lines 84-86 : Concatenation of the path, '/' and binary name               */
/* line 87     : Checking the existence of the file and we exiting the        */
/*				loop if access returns '0' 								      */
/* lines 94-95 : The binary is replaced by the absolute path or NULL if the   */
/*				binary does not exist                                         */
/*                                                                            */
/* ************************************************************************** */

void	make_magic_path(char ** cmd, char *path)
{
	int 	i;
	char	*bin;
	char	**path_split;

	i = 0;
	bin = NULL;
	path_split = NULL;
	path_split = split(path, ":");
	free(path);
	path = NULL;
	while (path_split[i]) 
	{
		bin = (char *)ft_calloc(sizeof(char),
		(strlen(path_split[i]) + 1 + strlen(cmd[0]) + 1));
		if (bin == NULL)
			break;
		strcat(bin, path_split[i]);
		strcat(bin, "/");
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
}

void	get_path(char **cmd)
{
	char	*path;
	
	path = NULL;
	path = ft_strdup(getenv("PATH"));
	if (path == NULL)
	path = ft_strdup("/bin:/usr/local/bin:/usr/bin:/bin:/usr/local/sbin");
	if (cmd[0][0] != '/' && ft_strncmp(cmd[0], "./", 2) != 0) 
		make_magic_path(cmd, path);
	else 
	{
		free(path);
		path = NULL;
	}
}