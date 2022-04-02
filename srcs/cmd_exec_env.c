/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_exec_env.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonte-l <abonte-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 13:18:24 by abonte-l          #+#    #+#             */
/*   Updated: 2022/04/02 13:00:33 by abonte-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

/* ************************************************************************** */
/*                           CMD_EXEC_ENV FUNCTION                            */
/*                                                                            */
/* lines 33-35 : forking parent and child processes                           */
/* lines 36-46 : If the fork was successful the parent process                */
/*              waits for the child (process fork)                            */
/* lines 38-39 : block the parent process until the child terminates          */
/*              then kill the child process                                   */
/* lines 43-46 : Child process execute command or exit if execve fails        */
/*                                                                            */
/* ************************************************************************** */

void	cmd_exec_env(char **cmd, char **envp)
{
	pid_t	pid;
	int		status;

	status = 0;
	pid = fork();
	if (pid == -1)
		perror("fork");
	else if (pid > 0) 
	{
		waitpid(pid, &status, 0);
		kill(pid, SIGTERM);
	} 
	else 
	{
		if (execve(cmd[0], cmd, envp) == -1)
			perror("shell");
		exit(EXIT_FAILURE);
	}
}