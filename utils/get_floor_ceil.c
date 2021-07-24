/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_floor_ceil.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhoyl <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 18:16:12 by hhoyl             #+#    #+#             */
/*   Updated: 2021/04/03 18:16:14 by hhoyl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

/*
** получаем floore с проверкой
*/

void	get_floore(char *tmp, t_all *kuba)
{
	if (ft_isdigit(*tmp))
		kuba->floor.r = ft_atoi(tmp);
	else
		error("Error\nCheck r for rgb Floor", kuba);
	tmp += ft_count_num(kuba->floor.r) + 1;
	if (ft_isdigit(*tmp))
		kuba->floor.g = ft_atoi(tmp);
	else
		error("Error\nCheck g for rgb Floor", kuba);
	tmp += ft_count_num(kuba->floor.g) + 1;
	if (ft_isdigit(*tmp))
		kuba->floor.b = ft_atoi(tmp);
	else
		error("Error\nCheck b for rgb Floor", kuba);
	tmp += ft_count_num(kuba->floor.b);
	if (*tmp)
		error("Error\nMore then need for rgb Floor", kuba);
}

/*
** получаем ceilling с проверкой
*/

void	get_ceilling(char *tmp, t_all *kuba)
{
	if (ft_isdigit(*tmp))
		kuba->ceiling.r = ft_atoi(tmp);
	else
		error("Error\nCheck r for rgb ceiling\n", kuba);
	tmp += ft_count_num(kuba->ceiling.r) + 1;
	if (ft_isdigit(*tmp))
		kuba->ceiling.g = ft_atoi(tmp);
	else
		error("Error\nCheck g for rgb ceiling\n", kuba);
	tmp += ft_count_num(kuba->ceiling.g) + 1;
	if (ft_isdigit(*tmp))
		kuba->ceiling.b = ft_atoi(tmp);
	else
		error("Error\nCheck b for rgb ceiling\n", kuba);
	tmp += ft_count_num(kuba->ceiling.g) + 1;
	if (*tmp)
		error("Error\nMore then need for rgb ceil", kuba);
}
