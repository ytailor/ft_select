/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytailor <ytailor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/06 13:20:17 by ytailor           #+#    #+#             */
/*   Updated: 2014/01/09 12:52:09 by ytailor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int					ft_putc(int c)
{
	int				fd;

	fd = open("/dev/tty", O_WRONLY);
	write(fd, &c, 1);
	close(fd);
	return (1);
}

int					ft_init(int ac, char **av, t_list **list, t_term term)
{
	int				i;
	char			*name_term;

	i = 1;
	while (i < ac)
	{
		*list = add_elem(av[i], *list, i - 1);
		i++;
	}
	if ((name_term = getenv("TERM")) == NULL)
		return (-1);
	if (tgetent(NULL, name_term) == -1)
		return (-1);
	if (tcgetattr(0, &term) == -1)
		return (-1);
	term.c_lflag &= ~(ICANON | ECHO);
	if (tcsetattr(0, TCSADRAIN, &term) == -1)
		return (-1);
	return (0);
}

void				ft_init_pos(t_pos *pos, t_list *list)
{
	pos->x = 0;
	pos->y = 0;
	if (list->next)
		pos->y_max = (list->prev)->pos;
	else
		pos->y_max = list->pos;
	pos->y_prev = 0;
	pos->fd = open("/dev/tty", O_WRONLY);
	ft_print_list(list, pos->fd);
}

void				ft_set_limit(t_pos *e)
{
	if (e->y == e->y_max + 1)
		e->y = 0;
	if (e->y == -1)
		e->y = e->y_max;
}

int					ft_restore_term(t_term term)
{
	tputs(tgetstr("te", NULL), 1, ft_putc);
	tputs(tgetstr("ve", NULL), 1, ft_putc);
	term.c_lflag |= ICANON;
	term.c_lflag |= ECHO;
	if (tcgetattr(0, &term) == -1)
		return (-1);
	if (tcsetattr(0, TCSANOW, &term) == -1)
		return (-1);
	return (0);
}
