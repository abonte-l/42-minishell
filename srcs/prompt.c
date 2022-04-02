
#include "../inc/minishell.h"

/* ************************************************************************** */
/*                              MAIN FUNCTION                                 */
/*                                                                            */
/* in main:                                                                   */
/* lines 74-75 : Duplicate envp in the linked list                            */
/* lines 76-77 : Allocation of the buffer which stores the command            */
/*               entered by the user                                          */
/* ---> make_magic_loop function                                              */
/* lines XX-XX : Aknowledging user that the prompt is closing then            */
/*               free the buffer                                              */
/*                                                                            */
/* in make_magic_loop:                                                        */
/* line 30     : Writing the prompt                                           */
/* lines 30-42 : Loop reading STDIN                                           */
/* line 32     : Spliting the string received to have command and arguments   */
/*               (and or options) separate                                    */
/* line 33     : Check if the command exist                                   */
/* line 35     : Check if it's a built in command                             */
/* line 36     : Execute the built in command                                 */
/* line 37     : Check if the binary                                          */
/* line 40     : Exec cmd with absolute path already gave in the prompt       */
/*                                                                            */
/* ************************************************************************** */

void	make_magic_loop(t_dlst *env_list, char **envp, char *buffer, char **cmd)
{
	while ((buffer = readline("$> ")) != NULL)
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
	printf("Bye \n");
	free(buffer);
}
