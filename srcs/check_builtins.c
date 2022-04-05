/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_builtins.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonte-l <abonte-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 11:52:21 by abonte-l          #+#    #+#             */
/*   Updated: 2022/04/05 11:55:57 by abonte-l         ###   ########.fr       */
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
	const char	*built_in[] = {"pwd", "cd", "env", "echo", "exit",
			"unset", "export", NULL};
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
