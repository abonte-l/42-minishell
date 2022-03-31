#ifndef _MINISHELL_H
# define _MINISHELL_H

//# include <pwd.h>
# include <signal.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <sys/wait.h>
//# include <sys/types.h>
//# include <linux/limits.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "../libft/inc/libft.h"

# define SUCCESS 0
# define ERROR -1
# define ERROR_TEXT	"Error\n"

# define INT_MAX 2147483647
# define INT_MIN -2147483648
# define INT_ERROR 2147483648

# define TRUE 1
# define FALSE 0

# define SPACE ' '
# define TAB '\t'
# define EOL '\n'
# define S_QUOTE '\''
# define D_QUOTE '"'
# define R_OUT '>'
# define R_IN '<'
# define PIPE '|'
# define VAR '$'

void	free_array(char **array);
void	get_path(char **cmd);
void	cmd_exec(char **cmd);
char 	**split(char *raw_data, char *limit);


#endif
