/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check_utils_two.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhoyl <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 13:49:17 by hhoyl             #+#    #+#             */
/*   Updated: 2021/04/06 13:49:19 by hhoyl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

/*
** check_errors_arg: проверка входных данных на ошибки.
*/

void	check_errors_arg(int ac, char **av, t_all *kuba)
{
	if (ac != 2 && ac != 3)
		error("Error\nNo more than 2 or 3 arguments were submitted", kuba);
	else if (ac == 2)
	{
		if (check_av_map(av[1]))
			error("Error\nMap is not called 'map.cub'", kuba);
	}
	else if (ac == 3)
	{
		if (ft_strlen(av[2]) != 6 || check_av_save(av[2]))
			error("Error\n3 the argument is not '--save'", kuba);
	}
}

/*
** check_tab: проверка на пробелы в конце строки.
*/

void	check_tab(char *line, t_all *kuba)
{
	if (line[ft_strlen(line) - 1] == ' ')
		error("Error\nA space was found after the indexer", kuba);
}

/*
** check_symbols_map_norm: функция для нормы.
*/

static	void	search_player(int *flag, int *i, int *j, t_all *kuba)
{
	if (ft_strchr("NEWS", kuba->map[*i][*j]))
	{
		if (*flag == 0)
		{
			*flag = 1;
			kuba->player_pos = &kuba->map[*i][*j];
			kuba->player_y = *i;
			kuba->player_x = *j;
		}
		else
			error("Error\n More then 1 player", kuba);
	}
}

/*
**проверяем все символы карты
*/

void	check_characters(int size, t_all *kuba)
{
	int	i;
	int	j;
	int	flag;

	i = 0;
	flag = 0;
	while (i != size)
	{
		j = 0;
		while (kuba->map[i][j] != '\0')
		{
			search_player(&flag, &i, &j, kuba);
			if (ft_strchr("012 NEWS", kuba->map[i][j]))
				++j;
			else
				error("Error\n check_characters", kuba);
		}
		i++;
	}
	if (flag == 0)
		error("Error\nNo player check_characters", kuba);
}
