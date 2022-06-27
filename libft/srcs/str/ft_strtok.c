/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonte-l <abonte-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 12:52:03 by abonte-l          #+#    #+#             */
/*   Updated: 2022/06/23 14:23:34 by abonte-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

//static char	*tmp_ptr = NULL;

char	*ft_strtok(char *str, char *delim)
{
	int j;
	int i;
	char *tok;

	i = 0;
	tok = NULL;
	if (!str || !delim)
		return (NULL);
	while (str[i]) {
		j = 0;
		while (delim[j]) {
			if (str[i] == delim[j]) {
				tok = ft_strndup(str, i);
				return (tok);
			}
			++j;
		}
		++i;
	}
	return (ft_strdup(str));
}
// 	size_t i;
// 	size_t j;
// 	size_t k;
// 	size_t l;
// 	char *final_ptr;

// 	i = 0;
// 	j = 0;
// 	k = 0;
// 	l = 0;

// 	static int flag = 0;
	
// 	final_ptr = NULL;
// 	if (delim == NULL)
// 		return NULL;
// 	if (flag == 1)
// 	{
// 		flag = 0;
// 		return (NULL);
// 	}
// 	if (str != NULL)
// 		tmp_ptr = str; 
// 	final_ptr = tmp_ptr;
	
// //	flag = flag;
// 	while (i <= (k = ft_strlen(tmp_ptr)))
// 	{
// 		j = 0;
// 		while (j < (l = ft_strlen(delim)))
// 		{
// 			if (tmp_ptr[i] == '\0') 
// 			{
// 				flag = 1;
// 				return (final_ptr);
// 			}
// 			if (tmp_ptr[i] == delim[j])
// 			{
// 				tmp_ptr[i] = '\0';
// 				tmp_ptr += i+1;
// 				return (final_ptr);
// 			}
// 			j++;
// 		}
// 		i++;
// 	}
// 	return NULL;
// }
