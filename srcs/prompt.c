/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonte-l <abonte-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 13:35:56 by abonte-l          #+#    #+#             */
/*   Updated: 2022/04/04 10:44:42 by abonte-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

/* ************************************************************************** */
/*                              MAIN FUNCTION                                 */
/*                                                                            */
/* in main:                                                                   */
/* line  70    : Duplicate envp in the linked list                            */
/* lines 71-76 : Allocation of the buffer which stores the command            */
/*               entered by the user                                          */
/* ---> line 77 : make_magic_loop function                                    */
/* lines 78-79  : Aknowledging user that the prompt is closing then           */
/*               free the buffer                                              */
/*                                                                            */
/* in make_magic_loop:                                                        */
/* line 41     : Writing the prompt                                           */
/* lines 41-53 : Loop reading STDIN                                           */
/* line 43     : Spliting the string received to have command and arguments   */
/*               (and or options) separate                                    */
/* line 44     : Check if the command exist                                   */
/* line 46     : Check if it's a built in command                             */
/* line 47     : Execute the built in command                                 */
/* line 48     : Check if the binary                                          */
/* line 51     : Exec cmd with absolute path already gave in the prompt       */
/*                                                                            */
/* ************************************************************************** */

void	make_magic_loop(t_dlst *env_list, char **envp, char *buffer, char **cmd)
{
	while ((buffer = readline("🌸minishell $> ")) != NULL)
	{
		cmd = split(buffer, " \n\t");
		if (cmd[0] == NULL)
			printf("Command not found\n");
		else if (iz_builtin(cmd[0]) == true)
			builtin_exec(cmd, env_list);
		else if (get_path(cmd, env_list) == true)
			cmd_exec_env(cmd, envp);
		else
			cmd_exec(cmd);
		free_array(cmd);
	}
}

int	main(int ac, char **av, char **envp)
{
	char	*buffer;
	size_t	buf_size;
	char	**cmd;
	t_dlst	*var_env_lst;

	(void)ac;
	(void)av;
	buffer = NULL;
	cmd = NULL;
	buf_size = 2048;
	var_env_lst = NULL;
	var_env_lst = dlist_new();
	dup_envp(envp, var_env_lst);
	buffer = (char *)ft_calloc(sizeof(char), buf_size);
	if (buffer == NULL) 
	{
		perror("Malloc failure");
		return (EXIT_FAILURE);
	}
	make_magic_loop(var_env_lst, envp, buffer, cmd);
	printf("exit \n");
	free(buffer);
}
