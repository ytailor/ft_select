/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytailor <ytailor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/06 17:10:42 by ytailor           #+#    #+#             */
/*   Updated: 2014/01/09 12:59:27 by ytailor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

t_tab   t[8] =
{
	{27, 65, ft_move_up},
	{27, 66, ft_move_down},
	{32, 0, ft_select},
	{127, 0, ft_delete},
	{27, 51, ft_delete},
	{10, 0, ft_return},
	{27, 0, ft_escape},
	{-1, -1, ft_escape}
};

int		ft_delete(t_pos *p, t_list **list)
{
	if ((*list)->pos == (*list)->next->pos)
		return (0);
	*list = delete_elem(*list, p->y);
	p->y_max = p->y_max - 1;
	tputs(tgetstr("cl", NULL), 1, ft_putc);
	ft_print_list(*list, p->fd);
	if (p->y > p->y_max)
	{
		p->y = 0;
		p->y_prev = p->y_prev - 1;
	}
	return (1);
}

int		ft_run(t_pos *e, t_list **list, char *buffer)
{
	int	i;

	i = 0;
	while (t[i].buff0 != -1)
	{
		if (buffer[0] == t[i].buff0 && buffer[2] == t[i].buff2)
			return (t[i].ptr_func(e, list));
		i++;
	}
	return (1);
}
