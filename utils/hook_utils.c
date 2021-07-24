/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook_utils_one.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhoyl <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 14:57:03 by hhoyl             #+#    #+#             */
/*   Updated: 2021/04/07 14:57:05 by hhoyl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	move_up(t_all *cub, double s)
{
	if (cub->map[(int)(cub->player.y + cub->player.dir_y * s)]
								[(int)(cub->player.x)] == '*')
		cub->player.y += cub->player.dir_y * s;
	if (cub->map[(int)(cub->player.y)]
			[(int)(cub->player.x + cub->player.dir_x * s)] == '*')
		cub->player.x += cub->player.dir_x * s;
}

void	move_back(t_all *cub, double s)
{
	if (cub->map[(int)(cub->player.y - cub->player.dir_y * s)]
								[(int)(cub->player.x)] == '*')
		cub->player.y -= cub->player.dir_y * s;
	if (cub->map[(int)(cub->player.y)]
			[(int)(cub->player.x - cub->player.dir_x * s)] == '*')
		cub->player.x -= cub->player.dir_x * s;
}

void	move_left(t_all *cub, double s)
{
	if (cub->map[(int)(cub->player.y - cub->player.dir_x * s)]
								[(int)(cub->player.x)] == '*')
		cub->player.y -= cub->player.dir_x * s;
	if (cub->map[(int)(cub->player.y)]
			[(int)(cub->player.x + cub->player.dir_y * s)] == '*')
		cub->player.x += cub->player.dir_y * s;
}

void	move_right(t_all *cub, double s)
{
	if (cub->map[(int)(cub->player.y + cub->player.dir_x * s)]
								[(int)(cub->player.x)] == '*')
		cub->player.y += cub->player.dir_x * s;
	if (cub->map[(int)(cub->player.y)]
			[(int)(cub->player.x - cub->player.dir_y * s)] == '*')
		cub->player.x -= cub->player.dir_y * s;
}

void	turn_right(t_all *cub, double r)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = cub->player.dir_y;
	old_plane_x = cub->player.plane_y;
	cub->player.dir_y = cub->player.dir_y * cos(-r)
		- cub->player.dir_x * sin(-r);
	cub->player.dir_x = old_dir_x * sin(-r) + cub->player.dir_x * cos(-r);
	cub->player.plane_y = cub->player.plane_y * cos(-r)
		- cub->player.plane_x * sin(-r);
	cub->player.plane_x = old_plane_x * sin(-r) + cub->player.plane_x * cos(-r);
}
