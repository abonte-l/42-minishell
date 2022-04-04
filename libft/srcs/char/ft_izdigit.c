#include "../inc/libft.h"

int	ft_izdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}