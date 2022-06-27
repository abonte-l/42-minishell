/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_exit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonte-l <abonte-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 18:05:21 by abonte-l          #+#    #+#             */
/*   Updated: 2022/06/23 15:46:09 by abonte-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	builtin_exit(char *arg) // ajouter un int pour l'argument (ce qui donne la valeur de retour)
{
	long int return_value;
	if (arg)
		return_value = ft_atoi(arg);
	else
		return_value = 0;
	long int i=256;
	int j = return_value % i ;
	printf("exit\n");
	exit(j);
}