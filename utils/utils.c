/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_utils_one.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhoyl <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 16:24:00 by hhoyl             #+#    #+#             */
/*   Updated: 2021/04/06 16:24:03 by hhoyl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	draw_world(t_print_map *n, t_all *kuba, int *x, int *y)
{
	if (*y < n->draw_start)
		my_mlx_pixel_put(&kuba->data, *x, *y,
			create_rgb(kuba->ceiling.r, kuba->ceiling.g, kuba->ceiling.b));
	if (*y >= n->draw_start && *y <= n->draw_end)
		side_world_norm(n, kuba, x, y);
	if (*y > n->draw_end && *y < kuba->res_h)
		my_mlx_pixel_put(&kuba->data, *x, *y,
			create_rgb(kuba->floor.r, kuba->floor.g, kuba->floor.b));
}

/*
** wallX точное значение точки удара о стен.
** Для понимания x-координаты текстуры мы должны использовать wallX
** Сначала узнаем координату x или y в мире,
** а затем вычитая из нее целое значение стены.
** Даже если он называется wallX,
** на самом деле это y-координата стены, если side == 1,
** но это всегда x-координата текстуры.
** texX - это координата x текстуры, и она вычисляется из wallX.
** Вычислить расстояние перпендикулярного луча
** (евклидово расстояние даст эффект рыбьего глаза!)
** line_height Вычислить высоту линии для рисования на экране
** вычисляем самый низкий и самый высокий пиксели для заполнения текущей полосы
*/

void	calc_other(t_print_map *n, t_all *cub, int *x)
{
	if (n->side == 0)
		n->perp_wall_dist = (n->map_x - cub->player.y
				+ (1 - n->step_x) / 2) / n->ray_dir_x;
	else
		n->perp_wall_dist = (n->map_y - cub->player.x
				+ (1 - n->step_y) / 2) / n->ray_dir_y;
	cub->close_sprite[*x] = n->perp_wall_dist;
	n->line_height = (int)(cub->res_h / n->perp_wall_dist);
	n->draw_start = -n->line_height / 2 + cub->res_h / 2;
	if (n->draw_start < 0)
		n->draw_start = 0;
	n->draw_end = n->line_height / 2 + cub->res_h / 2;
	if (n->draw_end >= cub->res_h)
		n->draw_end = cub->res_h - 1;
	if (n->side == 0)
		n->wall_x = cub->player.x + n->perp_wall_dist * n->ray_dir_y;
	else
		n->wall_x = cub->player.y + n->perp_wall_dist * n->ray_dir_x;
	n->wall_x -= floor((n->wall_x));
	n->tex_x = (int)(n->wall_x * (double)(TEXWIDTH));
	if (n->side == 0 && n->ray_dir_x > 0)
		n->tex_x = TEXWIDTH - n->tex_x - 1;
	if (n->side == 1 && n->ray_dir_y < 0)
		n->tex_x = TEXWIDTH - n->tex_x - 1;
}

/*
** переход к следующему квадрату карты, ИЛИ по оси x, ИЛИ по оси y
** Проверяем, попал ли луч в стену
*/

void	check_hit(t_print_map *n, t_all *cub)
{
	if (n->side_dist_x < n->side_dist_y)
	{
		n->side_dist_x += n->delta_dist_x;
		n->map_x += n->step_x;
		n->side = 0;
	}
	else
	{
		n->side_dist_y += n->delta_dist_y;
		n->map_y += n->step_y;
		n->side = 1;
	}
	if (cub->map[n->map_x][n->map_y] == '1')
		n->hit = 1;
}

/*
** вычисляем шаг и начальный sideDist
**(длина луча от текущей позиции до следующей стороны x или y)
*/

void	calc_step_start(t_print_map *n, t_all *kuba)
{
	if (n->ray_dir_x < 0)
	{
		n->step_x = -1;
		n->side_dist_x = (kuba->player.y - n->map_x) * n->delta_dist_x;
	}
	else
	{
		n->step_x = 1;
		n->side_dist_x = (n->map_x + 1.0 - kuba->player.y) * n->delta_dist_x;
	}
	if (n->ray_dir_y < 0)
	{
		n->step_y = -1;
		n->side_dist_y = (kuba->player.x - n->map_y) * n->delta_dist_y;
	}
	else
	{
		n->step_y = 1;
		n->side_dist_y = (n->map_y + 1.0 - kuba->player.x) * n->delta_dist_y;
	}
}

/*
** camera_x,ray_dir_x,ray_dir_y - вычисляем положение и направление
** map_x,map_y - в каком блоке карты мы находимся
** delta_dist_x, delta_dist_y  - длина луча от одной стороны
** x или y до следующей стороны x или y.
*/

void	ray_mapxy(t_print_map *n, int *x, t_all *kuba)
{
	n->camera_x = 2 * *x / (double)kuba->res_w - 1;
	n->ray_dir_x = kuba->player.dir_y + kuba->player.plane_y * n->camera_x;
	n->ray_dir_y = kuba->player.dir_x + kuba->player.plane_x * n->camera_x;
	n->map_x = (int)(kuba->player.y);
	n->map_y = (int)(kuba->player.x);
	n->delta_dist_x = sqrt(1 + (n->ray_dir_y * n->ray_dir_y)
			/ (n->ray_dir_x * n->ray_dir_x));
	n->delta_dist_y = sqrt(1 + (n->ray_dir_x * n->ray_dir_x)
			/ (n->ray_dir_y * n->ray_dir_y));
	n->hit = 0;
}
