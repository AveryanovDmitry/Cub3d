/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhoyl <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 16:42:13 by hhoyl             #+#    #+#             */
/*   Updated: 2021/04/03 16:42:50 by hhoyl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

/*
**вычисляем направление движения игрока
*/

static	void	calculat_direction(int x, int y, t_all *kuba)
{
	if (kuba->map[y][x] == 'N')
	{
		kuba->player.dir = (3 * PI) / 2;
		kuba->player.dir_symbol = 'N';
	}
	if (kuba->map[y][x] == 'W')
	{
		kuba->player.dir = PI;
		kuba->player.dir_symbol = 'W';
	}
	if (kuba->map[y][x] == 'E')
	{
		kuba->player.dir = 2 * PI;
		kuba->player.dir_symbol = 'E';
	}
	if (kuba->map[y][x] == 'S')
	{
		kuba->player.dir = PI / 2;
		kuba->player.dir_symbol = 'S';
	}
}

/*
**проверяем закрытость карты заливкой
*/

static	void	check_wall_map(int x, int y, t_all *kuba, int size_map)
{
	if (x < 0 || y < 0 || y >= size_map || x >= (int)ft_strlen(kuba->map[y]))
		error("Error\nCheck walls. check_wall_map", kuba);
	if (ft_strchr(" 02NWES", kuba->map[y][x]))
	{
		if (ft_strchr("NWES", kuba->map[y][x]))
			calculat_direction(x, y, kuba);
		if (kuba->map[y][x] == '2')
			kuba->map[y][x] = 't';
		else
			kuba->map[y][x] = '*';
		check_wall_map(x + 1, y, kuba, size_map);
		check_wall_map(x - 1, y, kuba, size_map);
		check_wall_map(x, y + 1, kuba, size_map);
		check_wall_map(x, y - 1, kuba, size_map);
	}
}

static	void	make_map(t_list **head, int size, t_all *kuba)
{
	int		i;
	t_list	*tmp;

	i = -1;
	tmp = *head;
	kuba->map = ft_calloc(size + 1, sizeof(char *));
	while (tmp)
	{
		kuba->map[++i] = tmp->content;
		tmp = tmp->next;
	}
	check_characters(size, kuba);
	check_space_in_wall(size, kuba);
	check_wall_map(kuba->player_x, kuba->player_y, kuba, size);
	kuba->size_map = size;
	ft_free_lst_map(head);
}

void	parser_map(int fd, t_all *kuba)
{
	char	*line;
	t_list	*map;

	map = NULL;
	if (fd == -1)
		error("Error\nfd == -1 parser_map", kuba);
	while (get_next_line(fd, &line))
	{
		ft_lstadd_back(&map, ft_lstnew(line));
	}
	ft_lstadd_back(&map, ft_lstnew(line));
	make_map(&map, ft_lstsize(map), kuba);
}
