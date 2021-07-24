/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhoyl <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 17:59:29 by hhoyl             #+#    #+#             */
/*   Updated: 2020/12/04 12:32:55 by hhoyl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFFER_SIZE 21

# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"

char		*ft_strchr(const char *s, int c);
int			get_next_line(int fd, char **line);
size_t		ft_strlen(const char *s);
char		*ft_strcpy(char *dst, const char *src);
char		*ft_strdup(const char *s1);

#endif
