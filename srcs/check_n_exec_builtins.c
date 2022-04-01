/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_n_exec_builtins.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonte-l <abonte-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 11:52:21 by abonte-l          #+#    #+#             */
/*   Updated: 2022/04/01 18:27:51 by abonte-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

/* ************************************************************************** */
/*                           IZ_BUILTIN FUNCTION                              */
/*                                                                            */
/*  line  27    : Array with all the built in functions available             */
/*                                                                            */
/*  lines 31-36 : Check every array's "cell" and return if the                */
/*              current command is a built in or not                          */
/*                                                                            */
/* ************************************************************************** */

bool	iz_builtin(char *cmd)
{
	const char	*built_in[] = {"pwd", "cd", "env", "echo", "exit", NULL};
	int i;
	
	i = 0;
	while (built_in[i]) 
	{
		if (!ft_strcmp(built_in[i], cmd))
			return (true);
		i++;
	}
	return (false);
}

/* ************************************************************************** */
/*                           BUILTIN_EXEC FUNCTION                            */
/*                                                                            */
/*  lines 49-52 : Check and dispatch to execute the right built in command    */
/*                                                                            */
/* ************************************************************************** */

void	builtin_exec(char **built_in, t_dlst *list)
{
	int	option;
	
	option = FALSE;
	if (!ft_strcmp(built_in[0], "pwd"))
		builtin_pwd();
	else if (!ft_strcmp(built_in[0], "cd"))
		builtin_cd(built_in[1]);
	else if (!strcmp(built_in[0], "env"))
		builtin_env(list);
	if (!ft_strcmp(built_in[0], "exit"))
		builtin_exit();
	else if (!strcmp(built_in[0], "echo"))
	{
		if (!strcmp(built_in[1], "-n"))
			option = TRUE;
		builtin_echo(option, built_in);
	}	
}