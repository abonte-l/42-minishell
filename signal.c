/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonte-l <abonte-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 20:04:36 by abonte-l          #+#    #+#             */
/*   Updated: 2022/07/04 09:45:32 by abonte-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

/* ************************************************************************** */
/*                         SINGINT_HANDLER  FUNCTION                          */
/*                                                                            */
/*  lines 28 : returns to the line                                            */
/*  lines 29 : reprint prompt on new line                                     */
/*  lines 30 : set the line to blank                                          */
/*  lines 31 : tell readline we're done                                       */
/*                                                                            */
/* ************************************************************************** */

void	sigint_handler(int sig)
{
	(void)sig;
	write(1, "\n", 1);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}