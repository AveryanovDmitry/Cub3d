/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook_utils_two.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhoyl <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 14:33:30 by hhoyl             #+#    #+#             */
/*   Updated: 2021/04/07 14:33:31 by hhoyl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	turn_left(t_all *cub, double r)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = cub->player.dir_y;
	old_plane_x = cub->player.plane_y;
	cub->player.dir_y = cub->player.dir_y * cos(r) - cub->player.dir_x * sin(r);
	cub->player.dir_x = old_dir_x * sin(r) + cub->player.dir_x * cos(r);
	cub->player.plane_y = cub->player.plane_y * cos(r)
		- cub->player.plane_x * sin(r);
	cub->player.plane_x = old_plane_x * sin(r) + cub->player.plane_x * cos(r);
}

/*
** печатает текст ошибки и выходит из программы.
*/

void	error(char *str, t_all *cub)
{
	(void)cub;
	ft_putendl_fd(str, 1);
	exit(1);
}

int	close_win(t_all *cub)
{
	mlx_destroy_window(cub->mlx, cub->mlx_win);
	exit(0);
	return (0);
}
