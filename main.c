/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytailor <ytailor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/01 17:57:18 by ytailor           #+#    #+#             */
/*   Updated: 2014/01/09 12:47:56 by ytailor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int						ft_select(t_pos *p, t_list **list)
{
	t_list				*tmp;

	tmp = *list;
	while (tmp->pos != p->y)
		tmp = tmp->next;
	if (tmp->select == 0)
	{
		tputs(tgetstr("mr", NULL), 1, ft_putc);
		ft_putstr_fd(tmp->arg, p->fd);
		tmp->select = 1;
		tputs(tgetstr("me", NULL), 1, ft_putc);
	}
	else
	{
		tputs(tgetstr("me", NULL), 1, ft_putc);
		ft_putstr_fd(tmp->arg, p->fd);
		tmp->select = 0;
	}
	p->y = p->y + 1;
	return (1);
}

void					ft_last_cursor(t_list *list, t_pos p, char *cm)
{
	t_list				*tmp;

	tmp = list;
	while (tmp->pos != p.y_prev)
		tmp = tmp->next;
	tputs(tgoto(cm, 0, p.y_prev), 1, ft_putc);
	if (tmp->select == 1)
		tputs(tgetstr("mr", NULL), 1, ft_putc);
	ft_putstr_fd(tmp->arg, p.fd);
	tputs(tgoto(cm, 0, p.y), 1, ft_putc);
	tputs(tgetstr("me", NULL), 1, ft_putc);
}

void					ft_cursor(t_list *list, t_pos *p, char *cm)
{
	t_list				*tmp;

	tmp = list;
	if (p->y != 0 || p->y_prev != 0)
		ft_last_cursor(list, *p, cm);
	while (tmp->pos != p->y)
		tmp = tmp->next;
	tputs(tgetstr("us", NULL), 1, ft_putc);
	if (tmp->select == 1)
		tputs(tgetstr("mr", NULL), 1, ft_putc);
	ft_putstr_fd(tmp->arg, p->fd);
	tputs(tgetstr("me", NULL), 1, ft_putc);
	tputs(tgoto(cm, 0, p->y), 1, ft_putc);
}

int						ft_get_key(t_list *list)
{
	char				*buffer;
	char				*res;
	t_pos				e;
	int					ret;

	ret = 1;
	ft_init_pos(&e, list);
	while (1)
	{
		buffer = ft_strnew(3);
		res = tgetstr("cm", NULL);
		ft_set_limit(&e);
		tputs(tgoto(res, e.x, e.y), 1, ft_putc);
		ft_cursor(list, &e, res);
		read(0, buffer, 3);
		e.y_prev = e.y;
		if ((ret = ft_run(&e, &list, buffer)) == 0 || ret == 2)
				return (ret);
		free(buffer);
	}
	return (0);
}

int						main(int ac, char **av)
{
	t_list				*list;
	t_term				term;
	int					ret;

	ret = 0;
	list = NULL;
	if (ac > 1)
	{
		ft_init(ac, av, &list, term);
		tputs(tgetstr("vi", NULL), 1, ft_putc);
		tputs(tgetstr("ti", NULL), 1, ft_putc);
		ft_select_signal();
		ret = ft_get_key(list);
		ft_restore_term(term);
		if (ret == 2)
			ft_print_select(list);
	}
	return (0);
}
