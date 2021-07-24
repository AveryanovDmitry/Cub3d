/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lala.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhoyl <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 16:57:28 by hhoyl             #+#    #+#             */
/*   Updated: 2020/11/02 17:46:15 by hhoyl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (!n)
		return (0);
	while (s1[i] == s2[i] && s1[i] && s2[i] && n > i)
		i++;
	if (n == i)
		i--;
	return (((unsigned char*)s1)[i] - ((unsigned char*)s2)[i]);
}
