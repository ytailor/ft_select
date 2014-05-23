/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select_key.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytailor <ytailor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/07 19:25:28 by ytailor           #+#    #+#             */
/*   Updated: 2014/01/09 12:57:04 by ytailor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		ft_move_up(t_pos *p, t_list **list)
{
	(void)list;
	p->y = p->y - 1;
	return (1);
}

int		ft_move_down(t_pos *p, t_list **list)
{
	(void)list;
	p->y = p->y + 1;
	return (1);
}

int		ft_return(t_pos *p, t_list **list)
{
	(void)list;
	(void)p;
	return (2);
}

int		ft_escape(t_pos *p, t_list **list)
{
	(void)list;
	close(p->fd);
	return (0);
}
