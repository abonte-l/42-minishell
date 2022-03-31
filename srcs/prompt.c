
#include "../inc/minishell.h"

/*
** lines 16-21 :allocation of the buffer which stores the command
** entered by the user
** line 22 : writing a prompt
** lines  : loop reading STDIN
*/

int	main(void)
{
	char	*buffer;
	size_t	buf_size;
	char	**cmd;
	//char	delim[] = {SPACE, TAB, EOL};

	buffer = NULL;
	cmd = NULL;
	buf_size = 2048;
	buffer = (char *)ft_calloc(sizeof(char), buf_size);
	if (buffer == NULL) 
	{
		perror("Malloc failure");
		return (EXIT_FAILURE);
	}
	while ((buffer = readline("$> ")) != NULL) 
	{
		cmd = split(buffer, " \n\t");
		get_path(cmd);
		if (cmd[0] == NULL)
			printf("Command not found\n");
		else
			cmd_exec(cmd);
		free_array(cmd);
	}
	printf("Bye \n");
	free(buffer);
}
