/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhoyl <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 15:21:58 by hhoyl             #+#    #+#             */
/*   Updated: 2021/04/06 15:22:00 by hhoyl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

/*
** преобразование RGB в hex.
*/

int	create_rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

/*
** берем пиксель из текстуры.
*/

unsigned	int	get_pixel(t_data *data, int x, int y)
{
	unsigned int	color;
	char			*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_pixel / 8));
	color = *(unsigned int *)dst;
	return (color);
}

/*
** my_mlx_pixel_put: измененная функция mlx_pixel_put
** для увеличения скорости работы.
*/

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_pixel / 8));
	*(unsigned int *)dst = color;
}
