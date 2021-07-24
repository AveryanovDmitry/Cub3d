/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screenshot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhoyl <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 15:08:27 by hhoyl             #+#    #+#             */
/*   Updated: 2021/04/07 15:08:29 by hhoyl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static	void	fill_screen(int fd, t_all *cub)
{
	int	i;
	int	j;
	int	color;

	i = cub->res_h;
	while (--i >= 0)
	{
		j = -1;
		while (++j < cub->res_w)
		{
			color = get_pixel(&cub->data, j, i);
			write(fd, &color, 4);
		}
	}
	exit(0);
}

static	void	for_norm2(int fd, int all_pix, int zero, int size)
{
	write(fd, &zero, 4);
	write(fd, &size, 4);
	all_pix = 1000;
	write(fd, &all_pix, 4);
	write(fd, &all_pix, 4);
	write(fd, &zero, 4);
	write(fd, &zero, 4);
}

static	void	for_norm(int fd)
{
	short	plane;

	plane = 1;
	write(fd, &plane, 2);
	plane = 32;
	write(fd, &plane, 2);
}

void	screenshot(t_all *kube)
{
	int		fd;
	int		all_pix;
	int		zero;
	int		pos_pix;
	int		size;

	fd = open("screen.bmp", O_CREAT | O_RDWR, 0777);
	all_pix = kube->res_w * kube->res_h * 4 + 54;
	zero = 0;
	pos_pix = 54;
	size = kube->res_w * kube->res_h;
	write(fd, "BM", 2);
	write(fd, &all_pix, 4);
	write(fd, &zero, 4);
	write(fd, &pos_pix, 4);
	pos_pix = 40;
	write(fd, &pos_pix, 4);
	write(fd, &kube->res_w, 4);
	write(fd, &kube->res_h, 4);
	for_norm(fd);
	for_norm2(fd, all_pix, zero, size);
	fill_screen(fd, kube);
}
