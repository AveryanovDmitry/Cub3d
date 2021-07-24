/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhoyl <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 05:32:22 by hhoyl             #+#    #+#             */
/*   Updated: 2020/11/16 15:26:26 by hhoyl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	*for_norminette(int n, int i, char *s)
{
	if (n == 0)
		s[0] = '0';
	if (n < 0)
		s[0] = '-';
	while (--i >= 0 && n != 0)
	{
		if (n >= 0)
			s[i] = 1 * (n % 10) + '0';
		else
			s[i] = -1 * (n % 10) + '0';
		n = n / 10;
	}
	return (s);
}

char			*ft_itoa(int n)
{
	int		i;
	int		temp;
	char	*s;

	i = 1;
	if (n < 0)
		i++;
	temp = n;
	while (temp /= 10)
		i++;
	if (!(s = malloc(sizeof(char) * (i + 1))))
		return (NULL);
	s[i] = '\0';
	return (for_norminette(n, i, s));
}
