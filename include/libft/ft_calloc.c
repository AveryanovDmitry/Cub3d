/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhoyl <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 20:57:10 by hhoyl             #+#    #+#             */
/*   Updated: 2020/11/15 18:28:29 by hhoyl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*dst;
	size_t	i;

	i = 0;
	dst = (void*)malloc(count * size);
	if (!dst)
		return (NULL);
	while (i < count * size)
	{
		dst[i] = 0;
		i++;
	}
	return (dst);
}
