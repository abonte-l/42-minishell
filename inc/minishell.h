#ifndef _MINISHELL_H
# define _MINISHELL_H

# include <signal.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <linux/limits.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "../libft/inc/libft.h"

# define SUCCESS 0
# define ERROR -1
# define ERROR_TEXT	"Error\n"

# define TRUE 1
# define FALSE 0

# define STDIN 0
# define STDOUT 1
# define STDERR 2

# define INT_MAX 2147483647
# define INT_MIN -2147483648
# define INT_ERROR 2147483648

# define D_QUOTE '"'
# define EOL '\n'
# define EQUAL '='
# define PIPE '|'
# define R_IN '<'
# define R_OUT '>'
# define SPACE ' '
# define S_QUOTE '\''
# define TAB '\t'
# define VAR '$'

bool	get_path(char **cmd, t_dlst *list);
void	cmd_exec_env(char **cmd, char **envp);
void	cmd_exec(char **cmd);
char 	**split(char *raw_data, char *limit);
bool	iz_builtin(char *cmd);
void	builtin_exec(char **built_in, t_dlst *list);
char 	**iz_special_char(t_dlst *list, char **cmd);

/*
** builtins functions
*/
void	builtin_cd(char *path);
void	builtin_pwd(void);
void	builtin_env(t_dlst *p_list);
void	builtin_echo(int option, char **built_in);
void	builtin_unset(char **built_in, t_dlst *list);
void	builtin_export(char **built_in, t_dlst *list);
void	builtin_exit(void);

/*
** utils functions
*/
void	free_array(char **array);
void	dup_envp(char **envp, t_dlst *var_env_lst);
char	*env_2_path(t_dlst *p_list, char *path);
void	indexation_env(t_dlst *list);

#endif
