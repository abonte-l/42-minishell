#include "../inc/libft.h"

char	*ft_strdup(const char *s1)
{
	char	*copy;
	int		i;

	i = 0;
	while (s1[i])
		++i;
	copy = malloc(sizeof(char) * (i + 1));
	if (!copy)
		return (0);
	i = 0;
	while (s1[i])
	{
		copy[i] = s1[i];
		++i;
	}
	copy[i] = '\0';
	return (copy);
}
