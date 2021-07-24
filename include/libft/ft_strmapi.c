/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhoyl <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 06:37:58 by hhoyl             #+#    #+#             */
/*   Updated: 2020/11/15 18:35:20 by hhoyl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str;
	unsigned int	i;

	i = 0;
	if (f && s)
	{
		while (s[i])
			i++;
		if (!(str = malloc(sizeof(char) * (i + 1))))
			return (NULL);
		str[i] = '\0';
		i = 0;
		while (s[i])
		{
			str[i] = (*f)(i, s[i]);
			i++;
		}
		return (str);
	}
	else
		return (NULL);
}
