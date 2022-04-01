/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_n_exec_builtins.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonte-l <abonte-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 11:52:21 by abonte-l          #+#    #+#             */
/*   Updated: 2022/04/01 12:11:08 by abonte-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

bool	iz_builtin(char *cmd)
{
	const char	*built_in[] = {"pwd", "cd", NULL};

	for (int i = 0; built_in[i]; i++) {
		if (!ft_strcmp(built_in[i], cmd))
			return (true);
	}
	return (false);
}

void	builtin_exec(char **built_in)
{
	if (!ft_strcmp(built_in[0], "pwd"))
		built_in_pwd();
	else if (!strcmp(built_in[0], "cd"))
		built_in_cd(built_in[1]);
}