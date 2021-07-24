/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhoyl <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 13:16:15 by hhoyl             #+#    #+#             */
/*   Updated: 2020/12/04 13:16:21 by hhoyl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_strnew(unsigned int size)
{
	char	*str;

	if (!(str = malloc(sizeof(char) * size + 1)))
		return (NULL);
	str[size] = '\0';
	while (size--)
		str[size] = '\0';
	return (str);
}

static void	ft_strclear(char **str)
{
	if (*str)
	{
		free(*str);
		*str = NULL;
	}
}

static char	*check_reminder(char **reminder, char **line)
{
	char *pointer_n;

	pointer_n = NULL;
	if (*reminder)
		if ((pointer_n = ft_strchr(*reminder, '\n')))
		{
			*pointer_n = '\0';
			*line = ft_strdup(*reminder);
			pointer_n++;
			ft_strcpy(*reminder, pointer_n);
		}
		else
		{
			*line = ft_strdup(*reminder);
			ft_strclear(&(*reminder));
		}
	else
		*line = ft_strnew(0);
	return (pointer_n);
}

int			get_next_line(int fd, char **line)
{
	char		buffer[BUFFER_SIZE + 1];
	int			byte_read;
	static char	*reminder;
	char		*pointer_n;
	char		*tmp;

	if ((-1 == read(fd, buffer, 0)) || !line || BUFFER_SIZE <= 0)
		return (-1);
	pointer_n = check_reminder(&reminder, line);
	while (!pointer_n && (byte_read = read(fd, buffer, BUFFER_SIZE)))
	{
		buffer[byte_read] = '\0';
		if ((pointer_n = ft_strchr(buffer, '\n')))
		{
			*pointer_n = '\0';
			if (!(reminder = ft_strdup(++pointer_n)))
				return (-1);
		}
		tmp = *line;
		if (!(*line = ft_strjoin(*line, buffer)))
			return (-1);
		free(tmp);
	}
	return (pointer_n ? 1 : 0);
}
