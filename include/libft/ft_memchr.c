/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhoyl <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 18:03:36 by hhoyl             #+#    #+#             */
/*   Updated: 2020/11/10 19:03:14 by hhoyl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t i;

	i = 0;
	while (i < n && (((unsigned char *)s)[i] != ((unsigned char)c)))
	{
		i++;
	}
	if (i == n)
	{
		return (NULL);
	}
	return ((void *)s + i);
}
