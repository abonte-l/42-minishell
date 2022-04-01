/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_echo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonte-l <abonte-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 17:02:12 by abonte-l          #+#    #+#             */
/*   Updated: 2022/04/01 17:04:50 by abonte-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	builtin_echo(int option, char **built_in)
{
	if (option == TRUE)
		printf("%s", built_in[2]);
	else
		printf("%s\n", built_in[1]);
}