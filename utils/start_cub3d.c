/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_cub3d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhoyl <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 16:09:15 by hhoyl             #+#    #+#             */
/*   Updated: 2021/04/06 16:09:17 by hhoyl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

/*
** выделяем память под масив спрайтов.
*/

static void	malloc_sprites(t_all *cub)
{
	cub->sp_x = malloc(sizeof(double) * cub->count_sprite);
	if (!(cub->sp_x))
		error("Error\nNo memory allocated", cub);
	cub->sp_y = malloc(sizeof(double) * cub->count_sprite);
	if (!(cub->sp_y))
		error("Error\nNo memory allocated", cub);
	cub->dist = malloc(sizeof(double) * cub->count_sprite);
	if (!(cub->dist))
		error("Error\nNo memory allocated", cub);
	cub->close_sprite = malloc(sizeof(double) * cub->res_w);
	if (!(cub->close_sprite))
		error("Error\nNo memory allocated", cub);
}

/*
** print_sprite: печать спрайта.
** stripe - перебираем каждую вертикальную полосу спрайта на экране
** условия в if:
** 1 он находится перед плоскостью камеры,
** поэтому вы не видите ничего позади себя
** 2 он на экране (слева)
** 3 он на экране (справа)
** 4 ZBuffer с перпендикулярным расстоянием
*/

static void	print_sprite(t_all *kube)
{
	t_print_sprite		s;
	int					i;
	int					y;
	int					stripe;

	i = -1;
	while (++i < kube->count_sprite)
	{
		calc_sprite(kube, &s, &i);
		stripe = s.draw_start_x;
		while (stripe < s.draw_end_x)
		{
			s.tex_x = (int)(256 * (stripe - (-s.sprite_width / 2
							+ s.sprite_screen_x)) * TEXWIDTH
					/ s.sprite_width) / 256;
			if (s.transform_y > 0 && stripe > 0 && stripe < kube->res_w
				&& s.transform_y < kube->close_sprite[stripe])
			{
				print_sprite_norm(kube, &s, &y, &stripe);
			}
			++stripe;
		}
	}
}

/*
** Печать карты.
** n.step - Насколько увеличить координату текстуры на пиксель экрана
** n.tex_pos - Начальная координата текстуры
*/

static void	print_map(t_all *kuba)
{
	t_print_map			n;
	int					x;
	int					y;

	kuba->data.img = mlx_new_image(kuba->mlx, kuba->res_w, kuba->res_h);
	kuba->data.addr = mlx_get_data_addr(kuba->data.img, &kuba->data.bits_pixel,
			&kuba->data.line_length, &kuba->data.endian);
	x = -1;
	while (++x < kuba->res_w)
	{
		ray_mapxy(&n, &x, kuba);
		calc_step_start(&n, kuba);
		while (n.hit == 0)
			check_hit(&n, kuba);
		calc_other(&n, kuba, &x);
		n.step = 1.0 * TEXHEIGHT / n.line_height;
		n.tex_pos = (n.draw_start - kuba->res_h
				/ 2 + n.line_height / 2) * n.step;
		y = -1;
		while (++y < kuba->res_h)
			draw_world(&n, kuba, &x, &y);
	}
	sort_sprite(kuba);
	print_sprite(kuba);
	mlx_put_image_to_window(kuba->mlx, kuba->mlx_win, kuba->data.img, 0, 0);
}

static int	key_hook(int keycode, t_all *cub)
{
	mlx_destroy_image(cub->mlx, cub->data.img);
	if (keycode == 13)
		move_up(cub, 0.1);
	if (keycode == 1)
		move_back(cub, 0.1);
	if (keycode == 0)
		move_left(cub, 0.1);
	if (keycode == 2)
		move_right(cub, 0.1);
	if (keycode == 124)
		turn_right(cub, 0.1);
	if (keycode == 123)
		turn_left(cub, 0.1);
	if (keycode == 53)
		close_win(cub);
	print_map(cub);
	return (0);
}

void	runner_cub(t_all *kuba, int argc)
{
	kuba->player.y = (double)kuba->player_y + 0.5;
	kuba->player.x = (double)kuba->player_x + 0.5;
	kuba->count_sprite = counting_sprites(kuba);
	malloc_sprites(kuba);
	save_position_sprites(kuba);
	direction_player(kuba);
	kuba->mlx = mlx_init();
	kuba->mlx_win = mlx_new_window(kuba->mlx, kuba->res_w,
			kuba->res_h, "cub3D");
	passing_texture(kuba);
	print_map(kuba);
	if (argc == 3)
		screenshot(kuba);
	else
	{
		mlx_hook(kuba->mlx_win, 2, 1L << 0, key_hook, kuba);
		mlx_hook(kuba->mlx_win, 17, 1L << 0, close_win, kuba);
		mlx_loop(kuba->mlx);
	}
}
