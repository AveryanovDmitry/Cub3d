/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhoyl <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 19:09:31 by hhoyl             #+#    #+#             */
/*   Updated: 2020/11/10 20:08:25 by hhoyl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t i;

	i = 0;
	if (!n)
	{
		return (0);
	}
	while (i < n && ((unsigned char *)s2)[i] == ((unsigned char *)s1)[i])
	{
		i++;
	}
	if (i == n)
	{
		return (0);
	}
	return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
}
