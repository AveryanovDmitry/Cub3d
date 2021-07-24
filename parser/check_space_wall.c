/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_space_wall.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhoyl <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 19:06:41 by hhoyl             #+#    #+#             */
/*   Updated: 2021/04/03 19:06:44 by hhoyl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

/*
**проверяем пустоту в стенах
*/

static int	fo_norm(t_all *kuba, int i, int j)
{
	if (kuba->map[i][j + 1] == ' ' || kuba->map[i][j + 1] == '\0'
	|| kuba->map[i][j - 1] == ' ' || kuba->map[i][j - 1] == '\0'
	|| kuba->map[i + 1][j] == ' ' || kuba->map[i + 1][j] == '\0'
	|| kuba->map[i - 1][j] == ' ' || kuba->map[i - 1][j] == '\0'
	|| kuba->map[i - 1][j - 1] == ' ' || kuba->map[i - 1][j - 1] == '\0'
	|| kuba->map[i - 1][j + 1] == ' ' || kuba->map[i - 1][j + 1] == '\0'
	|| kuba->map[i + 1][j + 1] == ' ' || kuba->map[i + 1][j + 1] == '\0'
	|| kuba->map[i + 1][j - 1] == ' ' || kuba->map[i + 1][j - 1] == '\0')
		return (1);
	return (0);
}

/*
**проверяем пустоту в стенах
*/

void	check_space_in_wall(int size, t_all *kuba)
{
	int	i;
	int	j;

	i = -1;
	while (++i != size)
	{
		j = 0;
		while (kuba->map[i][j] != '\0')
		{
			if ((i == 0 && kuba->map[i][j] == '0')
			|| (i == size - 1 && kuba->map[i][j] == '0'))
				error("Error\nzero in last or first line check_zero", kuba);
			else if (kuba->map[i][j] == '0')
			{
				if (fo_norm(kuba, i, j))
					error("Error\nCheck space in wall check_zero", kuba);
			}
			++j;
		}
	}
}
