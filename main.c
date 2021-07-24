/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhoyl <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 15:57:20 by hhoyl             #+#    #+#             */
/*   Updated: 2021/04/03 15:57:44 by hhoyl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	message_error(char *str)
{
	ft_putstr(str);
	exit(1);
}

int	check_arg(int ac, char **av)
{
	int		i;

	i = 0;
	if (ac < 2 || ac > 3)
		i = 1;
	if (ac == 2)
		if (ft_strncmp(av[1] + ft_strlen(av[1]) - 4, ".cub", 4) != 0)
			i = 1;
	if (ac == 3)
		if (ft_strcmp(av[2], "--save") != 0)
			i = 1;
	return (i);
}

int	main(int argc, char **argv)
{
	t_all	kuba;
	int		fd;

	if (check_arg(argc, argv) == 1)
	{
		ft_putstr("Error\ncheck_arg");
		return (1);
	}
	ft_bzero(&kuba, sizeof(kuba));
	fd = open(argv[1], O_RDONLY);
	if ((fd) && fd == -1)
		message_error("Error\nError open");
	if ((parsing_file(&kuba, fd, 0)) == 1)
		message_error("Error\nparsing_file");
	runner_cub(&kuba, argc);
	return (0);
}
