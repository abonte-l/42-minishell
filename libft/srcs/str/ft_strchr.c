/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonte-l <abonte-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 12:51:59 by abonte-l          #+#    #+#             */
/*   Updated: 2022/06/23 12:55:00 by abonte-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	ch;

	ch = (char)c;
	if (s[0] == ch)
	{
		return ((char *)s);
	}
	while (*s++)
	{
		if (*s == ch)
		{
			return ((char *)s);
		}
	}
	return (NULL);
}
