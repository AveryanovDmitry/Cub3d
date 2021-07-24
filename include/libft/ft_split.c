/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhoyl <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 17:13:26 by hhoyl             #+#    #+#             */
/*   Updated: 2020/11/17 19:58:02 by hhoyl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	strings_count(const char *s, char c)
{
	int	count_str;
	int	i;

	i = 0;
	count_str = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			count_str++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (count_str);
}

static char	*charcnt(char *str, char c)
{
	char	*array;
	int		i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	if (!(array = (char*)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = 0;
	while (str[i] && str[i] != c)
	{
		array[i] = str[i];
		i++;
	}
	array[i] = '\0';
	return (array);
}

static void	*go_free(char **list, int i)
{
	while (--i)
		free(list[i]);
	free(list);
	return (NULL);
}

char		**ft_split(char const *s, char c)
{
	char	**array;
	int		num_str;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	num_str = strings_count(s, c);
	array = (char**)malloc(sizeof(char*) * (num_str + 1));
	if (!array)
		return (NULL);
	while (i < num_str)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
			if (!(array[i] = charcnt((char *)s, c)))
				return (go_free(array, i));
		while (*s && *s != c)
			s++;
		i++;
	}
	array[i] = NULL;
	return (array);
}
