/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_sprite.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhoyl <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 15:57:31 by hhoyl             #+#    #+#             */
/*   Updated: 2021/04/06 15:57:32 by hhoyl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	for_norminette(t_all *cub)
{
	int	width;
	int	height;

	cub->t_spr.img = mlx_xpm_file_to_image(cub->mlx,
			cub->spr_tex, &width, &height);
	if (!(cub->t_spr.img))
		error("Error\nNo texture found for the sprite", cub);
	cub->t_spr.addr = mlx_get_data_addr(cub->t_spr.img,
			&cub->t_spr.bits_pixel, &cub->t_spr.line_length,
			&cub->t_spr.endian);
}

static void	for_norm(t_all *kuba)
{
	int	width;
	int	height;

	kuba->t_w.img = mlx_xpm_file_to_image(kuba->mlx,
			kuba->wes_tex, &width, &height);
	if (!(kuba->t_w.img))
		error("Error\nNo texture found for the West", kuba);
	kuba->t_w.addr = mlx_get_data_addr(kuba->t_w.img, &kuba->t_w.bits_pixel,
			&kuba->t_w.line_length, &kuba->t_w.endian);
	kuba->t_e.img = mlx_xpm_file_to_image(kuba->mlx,
			kuba->eas_tex, &width, &height);
	if (!(kuba->t_e.img))
		error("Error\nNo texture found for the East", kuba);
	kuba->t_e.addr = mlx_get_data_addr(kuba->t_e.img, &kuba->t_e.bits_pixel,
			&kuba->t_e.line_length, &kuba->t_e.endian);
}

/*
** get_sprite: схватываем текстуры и спрайт.
*/

void	passing_texture(t_all *kuba)
{
	int	width;
	int	height;

	kuba->t_n.img = mlx_xpm_file_to_image(kuba->mlx,
			kuba->nor_tex, &width, &height);
	if (!(kuba->t_n.img))
		error("Error\nNo texture found for North", kuba);
	kuba->t_n.addr = mlx_get_data_addr(kuba->t_n.img, &kuba->t_n.bits_pixel,
			&kuba->t_n.line_length, &kuba->t_n.endian);
	kuba->t_s.img = mlx_xpm_file_to_image(kuba->mlx,
			kuba->sou_tex, &width, &height);
	if (!(kuba->t_s.img))
		error("Error\nNo texture found for the South", kuba);
	kuba->t_s.addr = mlx_get_data_addr(kuba->t_s.img, &kuba->t_s.bits_pixel,
			&kuba->t_s.line_length, &kuba->t_s.endian);
	for_norm(kuba);
	for_norminette(kuba);
}
