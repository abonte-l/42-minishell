/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_var.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonte-l <abonte-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 14:29:29 by abonte-l          #+#    #+#             */
/*   Updated: 2022/04/01 14:42:33 by abonte-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

/* ************************************************************************** */
/*                           DUP_ENVP FUNCTION                                */
/*                                                                            */
/*  lines 28-32 : Loop on envp to stock all the variables in the              */
/*              double linked list                                            */
/*                                                                            */
/* ************************************************************************** */

void	dup_envp(char **envp, t_dlst *var_env_lst)
{
	int i;

	i = 0;
	while (envp[i])
	{
		dlist_add_end(var_env_lst, envp[i]);
		i++;
	}
}