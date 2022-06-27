/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_echo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonte-l <abonte-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 17:02:12 by abonte-l          #+#    #+#             */
/*   Updated: 2022/06/27 20:50:55 by abonte-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	builtin_echo(int option, char **built_in)
{
	int i;
	int j;

	i = 1;
	j = 2;
	size_t size = ft_tabsize(built_in);
	//printf("%li\n", size);	
		if (option == TRUE)
		{
			if (size > 2)
			{
				while (built_in[j])
				{
					printf("%s ", built_in[j]);
					++j;
				}
			}
			else
				printf("%c",7);
		}
					
		else
		{
			if (size > 1)
			{
				while (built_in[i])
				{
					printf("%s ", built_in[i]);
					++i;
				}

			}
			printf("\n");
		}
			
			

}