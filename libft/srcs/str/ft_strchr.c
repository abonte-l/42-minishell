#include "../inc/libft.h"

char		*ft_strchr(const char *s, int c)
{
	char	ch;

	ch = (char)c;
	if (s[0] == ch)
	{
		return ((char*)s);
	}
	while (*s++)
	{
		if (*s == ch)
		{
			return ((char*)s);
		}
	}
	return (NULL);
}