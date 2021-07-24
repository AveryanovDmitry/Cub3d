/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhoyl <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 18:10:16 by hhoyl             #+#    #+#             */
/*   Updated: 2020/11/24 16:00:56 by hhoyl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *str, int sym)
{
	while (*str)
	{
		if (*str == (char)sym)
			return ((char*)str);
		else
			str++;
	}
	if (sym == '\0')
		return ((char*)str);
	return (0);
}

char	*ft_strcpy(char *dst, const char *src)
{
	while (*src)
	{
		*dst = *src;
		src++;
		dst++;
	}
	*dst = '\0';
	return (dst);
}

char	*ft_strdup(const char *src)
{
	char	*str_dup;

	str_dup = NULL;
	str_dup = malloc(ft_strlen(src) + 1);
	if (str_dup == NULL)
		return (NULL);
	ft_strcpy(str_dup, src);
	return (str_dup);
}

char	*f_strjoin(char *s1, char *s2)
{
	char		*join;
	size_t		i;

	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (0);
	join = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (join == NULL)
		return (NULL);
	while (*s1)
	{
		join[i] = *s1;
		i++;
		s1++;
	}
	while (*s2)
	{
		join[i] = *s2;
		i++;
		s2++;
	}
	join[i] = '\0';
	return (join);
}
