/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhoyl <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 16:41:51 by hhoyl             #+#    #+#             */
/*   Updated: 2021/04/03 16:41:53 by hhoyl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	for_resolution(char *str, int i, t_all *kuba)
{
	char	*tmp;

	tmp = NULL;
	i++;
	while (str[i] == ' ' || str[i] == '\t')
		++i;
	tmp = &str[i];
	kuba->res_w = ft_atoi(tmp);
	tmp += ft_count_num(kuba->res_w);
	kuba->res_h = ft_atoi(tmp);
	check_resolution(kuba);
}

static void	floor_and_ceiling(char *str, int i, t_all *kuba)
{
	char	*tmp;

	if (str[i] == 'F')
	{
		i++;
		while (str[i] == ' ' || str[i] == '\t')
			++i;
		tmp = &str[i];
		get_floore(tmp, kuba);
		check_floor(kuba);
		check_space_in_rgb(tmp);
	}
	else if (str[i] == 'C')
	{
		i++;
		while (str[i] == ' ' || str[i] == '\t')
			++i;
		tmp = &str[i];
		get_ceilling(tmp, kuba);
		check_ceiling(kuba);
		check_space_in_rgb(tmp);
	}
}

static void	parser_texture(char *line, char x, int i, t_all *kuba)
{
	char	*tmp;

	tmp = NULL;
	while (line[i] == ' ' || line[i] == '\t')
		++i;
	tmp = &line[i];
	if (x == 'N')
		kuba->nor_tex = ft_substr(line, i, ft_strlen(tmp));
	else if (x == 'O')
		kuba->sou_tex = ft_substr(line, i, ft_strlen(tmp));
	else if (x == 'W')
		kuba->wes_tex = ft_substr(line, i, ft_strlen(tmp));
	else if (x == 'E')
		kuba->eas_tex = ft_substr(line, i, ft_strlen(tmp));
	else if (x == 'S')
		kuba->spr_tex = ft_substr(line, i, ft_strlen(tmp));
}

static void	check_texture(char *line, int i, t_all *kuba)
{
	if ((line[i++] == 'N') && (line[i] == 'O'))
		parser_texture(line, 'N', ++i, kuba);
	else if (line[--i] == 'S' && line[++i] == 'O')
		parser_texture(line, 'O', ++i, kuba);
	else if (line[i] == 'W' && line[++i] == 'E')
		parser_texture(line, 'W', ++i, kuba);
	else if (line[i] == 'E' && line[++i] == 'A')
		parser_texture(line, 'E', ++i, kuba);
	else if (line[--i] == 'S' && !ft_isalpha(line[++i]))
		parser_texture(line, 'S', i, kuba);
}

int	parsing_file(t_all *kuba, int fd, int count)
{
	char		*line;
	int			i;

	while (get_next_line(fd, &line) && count++ != 8)
	{
		if (ft_strlen(line) == 0)
			count--;
		else
		{
			i = 0;
			while (line[i] == ' ' || line[i] == '\t')
				++i;
			if (line[i] == 'R')
				for_resolution(line, i, kuba);
			if (ft_strchr("FC", line[i]))
				floor_and_ceiling(line, i, kuba);
			if (ft_strchr("NSWES", line[i]))
				check_texture(line, i, kuba);
		}
		free(line);
	}
	free(line);
	count_pars_data(kuba);
	parser_map(fd, kuba);
	return (0);
}
