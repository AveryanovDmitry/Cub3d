/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_data_parse.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhoyl <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 17:38:30 by hhoyl             #+#    #+#             */
/*   Updated: 2021/04/03 17:38:36 by hhoyl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

/*
**проверяем что все данные с карты считаны один раз
*/

void	count_pars_data(t_all *kuba)
{
	if (kuba->res_h == 0 || kuba->res_w == 0
		|| ft_strlen(kuba->nor_tex) == 0
		|| ft_strlen(kuba->sou_tex) == 0 || ft_strlen(kuba->wes_tex) == 0
		|| ft_strlen(kuba->eas_tex) == 0 || ft_strlen(kuba->spr_tex) == 0
		|| kuba->floore_flag != 1 || kuba->ceilling_flag != 1)
	{
		message_error("Error\ncount_pars_data");
	}
}

/*
**проверка на пробелы в цветах
*/

void	check_space_in_rgb(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] == ' ')
			message_error("Error\ncheck_space_in_rgb");
		++i;
	}
}

void	check_ceiling(t_all *cub)
{
	if ((cub->ceiling.r > 255 || cub->ceiling.r < 0)
		|| (cub->ceiling.g > 255 || cub->ceiling.g < 0)
		|| (cub->ceiling.b > 255 || cub->ceiling.b < 0))
		error("Error\ncheck_celling", cub);
	cub->ceilling_flag = 1;
}

void	check_floor(t_all *kuba)
{
	if ((kuba->floor.r > 255 || kuba->floor.r < 0)
		|| (kuba->floor.g > 255 || kuba->floor.g < 0)
		|| (kuba->floor.b > 255 || kuba->floor.b < 0))
		error("Error\ncheck_floor", kuba);
	kuba->floore_flag = 1;
}

void	check_resolution(t_all *kuba)
{
	int	width;
	int	height;

	mlx_get_screen_size(&kuba->mlx, &width, &height);
	if (kuba->res_w <= 10 || kuba->res_h <= 10)
		error("Error\nCheck resolution", kuba);
	if (kuba->res_w > width || kuba->res_h > height)
	{
		kuba->res_w = width;
		kuba->res_h = height;
	}
}
