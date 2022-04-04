#include "../inc/libft.h"

int		ft_izalnum(int c)
{
	if (ft_izdigit(c) || ft_izalpha(c))
		return (1);
	else
		return (0);
}