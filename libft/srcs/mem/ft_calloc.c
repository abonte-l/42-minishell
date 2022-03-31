#include "../inc/libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*mem;

	mem = (char *)malloc(count * size);
	if (!mem)
		return (0);
	ft_bzero(mem, count * size);
	return ((void *)mem);
}
