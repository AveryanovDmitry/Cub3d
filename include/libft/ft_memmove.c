/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhoyl <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 20:13:52 by hhoyl             #+#    #+#             */
/*   Updated: 2020/11/10 22:15:26 by hhoyl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	if (dest - src > 0)
	{
		while (len > 0)
		{
			len--;
			((char*)dest)[len] = ((char*)src)[len];
		}
		return (dest);
	}
	ft_memcpy(dest, src, len);
	return (dest);
}
