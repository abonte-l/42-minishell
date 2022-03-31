/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_pwd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonte-l <abonte-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 19:05:23 by abonte-l          #+#    #+#             */
/*   Updated: 2022/03/31 19:05:56 by abonte-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	built_in_pwd(void)
{
	char cwd[PATH_MAX];
	
	if (getcwd(cwd, sizeof(cwd)) != NULL)
	       printf("%s\n", cwd);
	else
		perror("getcwd()");
}