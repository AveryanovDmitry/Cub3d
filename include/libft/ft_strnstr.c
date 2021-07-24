/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhoyl <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 22:21:44 by hhoyl             #+#    #+#             */
/*   Updated: 2020/11/15 18:31:56 by hhoyl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (haystack[i] && needle[j] && len > 0)
	{
		j = 0;
		if (needle[j] != haystack[i])
		{
			i++;
			len--;
		}
		while (needle[j] == haystack[i] && len > 0 && haystack[i])
		{
			j++;
			i++;
			len--;
		}
	}
	if (needle[j] == '\0')
		return ((char*)haystack + (i - j));
	return (NULL);
}
