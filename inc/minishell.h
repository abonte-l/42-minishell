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

/*
** defining node of the linked list
*/
typedef struct		s_node
{
	char			*data;
	int				index;
	struct s_node 	*next;
	struct s_node	*prev;
}					t_node;

/*
** defining a double linked list
*/
typedef struct		s_dlst
{
	int				length;
	struct s_node 	*tail;
	struct s_node	*head;
}					t_dlst;

/*
** double linked list functions
*/
t_dlst	*dlist_new(void);
t_dlst	*dlist_add_end(t_dlst *list, char *data);
t_dlst	*dlist_add_start(t_dlst *list, char *data);
void 	dlist_delete(t_dlst **list);
void	new_node_end(t_dlst *list, t_node *new_node, char *data);
void	new_node_start(t_dlst *list, t_node *new_node, char *data);

void	free_array(char **array);

char **split(char *raw_data, char *limit);

void	get_path(char **cmd);

void	cmd_exec(char **cmd);



#endif
