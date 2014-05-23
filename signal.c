/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytailor <ytailor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/09 11:23:19 by ytailor           #+#    #+#             */
/*   Updated: 2014/01/12 16:21:13 by ytailor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void		ft_select_signal(void)
{
	signal(SIGINT, signal_handler);
	signal(SIGTERM, signal_handler);
	signal(SIGTSTP, signal_handler);
	signal(SIGCONT, signal_handler);
}

void		signal_handler(int sig)
{
	if (sig == SIGINT || sig == SIGTERM)
		ft_ctrl_c();
	if (sig == SIGTSTP)
		ft_ctrl_z();
	if (sig == SIGCONT)
		ft_fg();
}

void		ft_ctrl_c(void)
{
	tputs(tgetstr("te", NULL), 1, ft_putc);
	tputs(tgetstr("ve", NULL), 1, ft_putc);
	exit(0);
}

void		ft_ctrl_z(void)
{
	tputs(tgetstr("te", NULL), 1, ft_putc);
	tputs(tgetstr("ve", NULL), 1, ft_putc);
	signal(SIGTSTP, SIG_DFL);
	exit(0);
}

void		ft_fg(void)
{
	tputs(tgetstr("vi", NULL), 1, ft_putc);
	tputs(tgetstr("ti", NULL), 1, ft_putc);
}
