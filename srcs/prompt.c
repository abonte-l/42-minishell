
#include "../inc/minishell.h"

/*
** lines 20-25 :allocation of the buffer which stores the command
** entered by the user 01
** line 22 : writing a prompt 02
** lines  : loop reading STDIN (-->tout le while ((buffer = readline("$> ")) != NULL))
*/

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
	buffer = (char *)ft_calloc(sizeof(char), buf_size); //01
	if (buffer == NULL) 
	{
		perror("Malloc failure");
		return (EXIT_FAILURE);
	}
	while ((buffer = readline("$> ")) != NULL) //02
	{
		cmd = split(buffer, " \n\t");
		if (cmd[0] == NULL) //check if the command exist
			printf("Command not found\n");
		else if (iz_builtin(cmd[0]) == true) //check if it's a built in command
			builtin_exec(cmd, var_env_lst);//execute the built in command
		else if (get_path(cmd, var_env_lst) == true) //check if the binary
			cmd_exec_env(cmd, envp);
		else
			cmd_exec(cmd); //exec cmd with absolute path already gave in the prompt
		free_array(cmd);
	}
	printf("Bye \n");
	free(buffer);
}
