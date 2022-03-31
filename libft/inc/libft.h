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

void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
void		*ft_realloc(void *ptr, size_t size);
void	*ft_memcpy(void *dst, const void *src, size_t n);
char	*ft_strdup(const char *s1);
char 	*ft_strtok(char *str, char *delim);
char	*ft_strcat(char *dest, const char *src);
size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

#endif