/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytailor <ytailor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/03 16:16:07 by ytailor           #+#    #+#             */
/*   Updated: 2014/01/12 18:18:39 by ytailor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

t_list			*create_elem(char *av, int i)
{
	t_list		*new_elem;

	new_elem = (t_list*)malloc(sizeof(t_list));
	new_elem->next = NULL;
	new_elem->prev = NULL;
	new_elem->arg = av;
	new_elem->pos = i;
	new_elem->select = 0;
	return (new_elem);
}

t_list			*add_elem(char *av, t_list *list, int pos)
{
	t_list		*tmp;
	t_list		*new_elem;
	int			i;

	i = 1;
	new_elem = create_elem(av, pos);
	tmp = list;
	if (list == NULL)
		return (new_elem);
	else
	{
		while (tmp->pos != pos - 1)
			tmp = tmp->next;
		tmp->next = new_elem;
		new_elem->prev = tmp;
		new_elem->next = list;
		list->prev = new_elem;
		return (list);
	}
}

void			ft_print_list(t_list *list, int fd)
{
	t_list		*tmp;

	tmp = list;
	if (tmp->select == 1)
		tputs(tgetstr("mr", NULL), 1, ft_putc);
	ft_putendl_fd(tmp->arg, fd);
	tputs(tgetstr("me", NULL), 1, ft_putc);
	tmp = tmp->next;
	if (tmp != NULL)
	{
		while (tmp->pos != 0)
		{
			if (tmp->select == 1)
				tputs(tgetstr("mr", NULL), 1, ft_putc);
			ft_putendl_fd(tmp->arg, fd);
			tputs(tgetstr("me", NULL), 1, ft_putc);
			tmp = tmp->next;
		}
	}
}

t_list			*delete_elem(t_list *list, int pos)
{
	t_list		*tmp;

	tmp = list;
	tmp = tmp->prev;
	while (tmp->pos != pos)
	{
		tmp->pos = tmp->pos - 1;
		tmp = tmp->prev;
	}
	if (tmp->pos == list->pos)
		list = list->next;
	(tmp->prev)->next = tmp->next;
	(tmp->next)->prev = tmp->prev;
	free(tmp);
	return (list);
}

int				ft_print_select(t_list *list)
{
	t_list		*tmp;

	tmp = list;
	tputs(tgetstr("me", NULL), 1, ft_putc);
	if (tmp != NULL)
	{
		while ((tmp->next)->pos != 0)
		{
			if (tmp->select == 1)
			{
				ft_putstr(tmp->arg);
				ft_putchar(' ');
			}
			tmp = tmp->next;
		}
		if (tmp->select == 1)
		{
			ft_putstr(tmp->arg);
			ft_putchar(' ');
		}
	}
	return (1);
}
