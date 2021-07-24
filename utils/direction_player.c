/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_dir_plr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhoyl <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 14:42:02 by hhoyl             #+#    #+#             */
/*   Updated: 2021/04/07 14:42:04 by hhoyl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static	void	for_norminette(t_all *cub)
{
	if (cub->player.dir_symbol == 'W')
	{
		cub->player.dir_y = 0;
		cub->player.dir_x = -1;
		cub->player.plane_y = -0.66;
		cub->player.plane_x = 0;
	}
	else if (cub->player.dir_symbol == 'E')
	{
		cub->player.dir_y = 0;
		cub->player.dir_x = 1;
		cub->player.plane_y = 0.66;
		cub->player.plane_x = 0;
	}
}

/*
** установка направления персонажа.
*/

void	direction_player(t_all *cub)
{
	if (cub->player.dir_symbol == 'N')
	{
		cub->player.dir_y = -1;
		cub->player.dir_x = 0;
		cub->player.plane_y = 0;
		cub->player.plane_x = 0.66;
	}
	else if (cub->player.dir_symbol == 'S')
	{
		cub->player.dir_y = 1;
		cub->player.dir_x = 0;
		cub->player.plane_y = 0;
		cub->player.plane_x = -0.66;
	}
	else
		for_norminette(cub);
}
