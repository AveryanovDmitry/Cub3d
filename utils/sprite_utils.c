/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhoyl <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 15:26:59 by hhoyl             #+#    #+#             */
/*   Updated: 2021/04/06 15:27:08 by hhoyl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

/*
** сохранить позицию спрайтов
** и вернуть их количество.
*/

void	save_position_sprites(t_all *cub)
{
	int	i;
	int	j;
	int	coll;

	i = 0;
	coll = 0;
	while (cub->map[i])
	{
		j = 0;
		while (cub->map[i][j] != '\0')
		{
			if (cub->map[i][j] == 't')
			{
				cub->sp_x[coll] = j + 0.5;
				cub->sp_y[coll] = i + 0.5;
				coll++;
			}
			++j;
		}
		++i;
	}
}

/*
** подсчет спрайтов.
*/

int	counting_sprites(t_all *cub)
{
	int	i;
	int	j;
	int	coll;

	i = 0;
	coll = 0;
	while (cub->map[i])
	{
		j = 0;
		while (cub->map[i][j] != '\0')
		{
			if (cub->map[i][j] == 't')
				coll++;
			++j;
		}
		++i;
	}
	return (coll);
}

/*
** переместить местами спрайты.
*/

static void	swap_sprite(t_all *cub, int *j)
{
	float	tmp;

	tmp = cub->dist[*j - 1];
	cub->dist[*j - 1] = cub->dist[*j];
	cub->dist[*j] = tmp;
	tmp = cub->sp_x[*j - 1];
	cub->sp_x[*j - 1] = cub->sp_x[*j];
	cub->sp_x[*j] = tmp;
	tmp = cub->sp_y[*j - 1];
	cub->sp_y[*j - 1] = cub->sp_y[*j];
	cub->sp_y[*j] = tmp;
}

/*
** сортировка метод "пузырька".
*/

static void	sort_bubble(t_all *kube)
{
	int	i;
	int	j;

	i = 1;
	while (i < kube->count_sprite)
	{
		j = i;
		while ((int)kube->dist[j] > (int)kube->dist[j - 1] && j != 0)
		{
			swap_sprite(kube, &j);
			--j;
		}
		++i;
	}
}

/*
** sort_sprite: сортировка спрайтов.
*/

void	sort_sprite(t_all *kube)
{
	int	i;

	i = -1;
	while (++i < kube->count_sprite)
	{
		kube->dist[i] = ((kube->player.x - kube->sp_x[i])
				* (kube->player.x - kube->sp_x[i])
				+ (kube->player.y - kube->sp_y[i])
				* (kube->player.y - kube->sp_y[i]));
	}
	if (kube->count_sprite > 1)
		sort_bubble(kube);
}
