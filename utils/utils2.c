/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_utils_two.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhoyl <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 16:23:36 by hhoyl             #+#    #+#             */
/*   Updated: 2021/04/06 16:23:38 by hhoyl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

/*
** side_world_norm: функция для нормы.
*/

void	side_world_norm(t_print_map *n, t_all *cub, int *x, int *y)
{
	n->tex_y = (int)n->tex_pos & (TEXHEIGHT - 1);
	n->tex_pos += n->step;
	if (n->side == 0)
	{
		if (n->step_x > 0)
			my_mlx_pixel_put(&cub->data, *x, *y,
				get_pixel(&cub->t_s, n->tex_x, n->tex_y));
		else
			my_mlx_pixel_put(&cub->data, *x, *y,
				get_pixel(&cub->t_n, n->tex_x, n->tex_y));
	}
	else
	{
		if (n->step_y > 0)
			my_mlx_pixel_put(&cub->data, *x, *y,
				get_pixel(&cub->t_e, n->tex_x, n->tex_y));
		else
			my_mlx_pixel_put(&cub->data, *x, *y,
				get_pixel(&cub->t_w, n->tex_x, n->tex_y));
	}
}

/*
** после сортировки спрайтов делаем проекцию и рисуем их
** переводим положение спрайта относительно камеры
** преобразовываем спрайт с помощью обратной матрицы камеры
** invDet требуется для правильного умножения матриц
** это глубина внутри экрана, это то, что есть Z в 3D
** вычисляем высоту спрайта на экране
** вычисляем ширину спрайта
** вычисляем самый низкий и
** самый высокий пиксели для заполнения текущей полосы
*/

void	calc_sprite(t_all *kube, t_print_sprite *s, int *i)
{
	s->sprite_x = kube->sp_x[*i] - kube->player.x;
	s->sprite_y = kube->sp_y[*i] - kube->player.y;
	s->invdet = 1.0 / (kube->player.plane_x * kube->player.dir_y
			- kube->player.dir_x * kube->player.plane_y);
	s->transform_x = s->invdet * (kube->player.dir_y * s->sprite_x
			- kube->player.dir_x * s->sprite_y);
	s->transform_y = s->invdet * (-kube->player.plane_y * s->sprite_x
			+ kube->player.plane_x * s->sprite_y);
	s->sprite_screen_x = (int)((kube->res_w / 2)
			* (1 + s->transform_x / s->transform_y));
	s->sprite_height = abs((int)(kube->res_h / (s->transform_y)));
	s->draw_start_y = -s->sprite_height / 2 + kube->res_h / 2;
	if (s->draw_start_y < 0)
		s->draw_start_y = 0;
	s->draw_end_y = s->sprite_height / 2 + kube->res_h / 2;
	if (s->draw_end_y >= kube->res_h)
		s->draw_end_y = kube->res_h - 1;
	s->sprite_width = abs((int)(kube->res_h / (s->transform_y)));
	s->draw_start_x = -s->sprite_width / 2 + s->sprite_screen_x;
	if (s->draw_start_x < 0)
		s->draw_start_x = 0;
	s->draw_end_x = s->sprite_width / 2 + s->sprite_screen_x;
	if (s->draw_end_x >= kube->res_w)
		s->draw_end_x = kube->res_w - 1;
}

/*
** для каждого пикселя текущей полосы
** d - 256 и 128 факторов, чтобы избежать поплавков
** получаем текущий цвет из текстуры
** закрашиваем пиксель, если он не черный,
** невидимый цвет - черный
*/

void	print_sprite_norm(t_all *kube, t_print_sprite *s,
										int *y, int *stripe)
{
	*y = s->draw_start_y;
	while (*y < s->draw_end_y)
	{
		s->d = (*y) * 256 - kube->res_h
			* 128 + s->sprite_height * 128;
		s->tex_y = ((s->d * TEXHEIGHT) / s->sprite_height) / 256;
		s->color = get_pixel(&kube->t_spr, s->tex_x, s->tex_y);
		if (s->color != 0)
			my_mlx_pixel_put(&kube->data, *stripe, *y, s->color);
		(*y)++;
	}
}
