#include "../inc/libft.h"

char	*ft_strcat(char *dest, const char *src)
{
	size_t	i;
	size_t	j;

	if (!src || !dest)
		return (dest);
	i = 0;
	while (dest[i])
		++i;
	j = 0;
	while (src[j])
	{
		dest[i] = src[j];
		++i;
		++j;
	}
	dest[i] = 0;
	return (dest);
}