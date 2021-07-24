/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhoyl <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 14:13:00 by hhoyl             #+#    #+#             */
/*   Updated: 2020/11/15 18:42:02 by hhoyl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dest;
	int		i;

	if (!s)
		return (NULL);
	i = 0;
	if (ft_strlen(s) < start)
	{
		dest = malloc(sizeof(char));
		*dest = '\0';
		return (dest);
	}
	dest = malloc(len * sizeof(char) + 1);
	if (dest == NULL)
		return (NULL);
	while (len > 0)
	{
		dest[i] = s[start];
		i++;
		start++;
		len--;
	}
	dest[i] = '\0';
	return (dest);
}
