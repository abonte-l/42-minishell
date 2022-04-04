#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>

# define SUCCESS 0
# define ERROR -1
# define ERROR_TEXT	"Error\n"

# define INT_MAX 2147483647
# define INT_MIN -2147483648
# define INT_ERROR 2147483648

# define TRUE 1
# define FALSE 0

# define SIZE_OF_STRING 50 
# define SIZE_OF_DELIM 5

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
t_dlst	*dlist_delete_node(t_dlst *list, char *data);
void 	dlist_delete(t_dlst **list);
void	new_node_end(t_dlst *list, t_node *new_node, char *data);
void	new_node_start(t_dlst *list, t_node *new_node, char *data);
void 	dlist_display(t_dlst *p_list);

/*
** memory functions
*/
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
void	*ft_realloc(void *ptr, size_t size);
void	*ft_memcpy(void *dst, const void *src, size_t n);

/*
** string functions
*/
char	*ft_strdup(const char *s1);
char	*ft_strchr(const char *s, int c);
char 	*ft_strtok(char *str, char *delim);
char	*ft_strndup(const char *s1, size_t n);
char	*ft_strcpy(char *dest, const char *src);
char	*ft_strcat(char *dest, const char *src);
char	*ft_strncpy(char *s1, const char *s2, size_t n);
size_t	ft_strlen(const char *s);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	ft_putstr(char const *s);
void	ft_putstr_fd(char const *s, int fd);

/*
** char functions
*/
int		ft_izalpha(int c);
int		ft_izdigit(int c);
int		ft_izalnum(int c);
void	ft_putchar(char c);
void	ft_putchar_fd(char c, int fd);

#endif