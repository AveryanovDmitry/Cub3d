/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhoyl <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 17:21:08 by hhoyl             #+#    #+#             */
/*   Updated: 2021/04/03 17:21:10 by hhoyl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ft_lstlast: Возвращает последний элемент списка.
*/

t_list	*ft_lstlast(t_list *lst)
{
	t_list *p;
	t_list *l;

	p = lst;
	l = p;
	while (p != NULL)
	{
		l = p;
		p = p->next;
	}
	return (l);
}
