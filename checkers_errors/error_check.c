/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhoyl <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 20:06:02 by hhoyl             #+#    #+#             */
/*   Updated: 2021/04/07 20:06:04 by hhoyl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

/*
** check_av_tree: проверка на название '--save'.
*/

int	check_av_save(char *av)
{
	if (av[0] == '-' && av[1] == '-' && av[2] == 's'
		&& av[3] == 'a' && av[4] == 'v' && av[5] == 'e')
		return (0);
	else
		return (1);
}

/*
** check_av_one: проверка на расширение '.cub'.
*/

int	check_av_map(char *av)
{
	if (av[ft_strlen(av) - 1] == 'b' && av[ft_strlen(av) - 2] == 'u'
		&& av[ft_strlen(av) - 3] == 'c' && av[ft_strlen(av) - 4] == '.')
		return (0);
	else
		return (1);
}
