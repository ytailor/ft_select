/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytailor <ytailor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/01 18:03:33 by ytailor           #+#    #+#             */
/*   Updated: 2014/01/12 16:19:40 by ytailor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

# include "libft/includes/libft.h"
# include <termios.h>
# include <termcap.h>
# include <unistd.h>
# include <term.h>
# include <stdlib.h>
# include <curses.h>
# include <fcntl.h>

typedef struct		termios t_term;

typedef struct		s_list
{
	char			*arg;
	struct s_list	*next;
	struct s_list	*prev;
	int				pos;
	int				select;
}					t_list;

typedef	struct		s_pos
{
	int				x;
	int				y;
	int				y_max;
	int				y_prev;
	int				fd;
}					t_pos;

typedef struct		s_tab
{
	int				buff0;
	int				buff2;
	int				(*ptr_func)(t_pos *, t_list **);
}					t_tab;

int			ft_putc(int c);
int			ft_init(int ac, char **av, t_list **list, t_term term);
int			ft_select(t_pos *p, t_list **list);
void		ft_last_cursor(t_list *list, t_pos p, char *cm);
void		ft_cursor(t_list *list, t_pos *p, char *cm);
int			ft_get_key(t_list *list);
void        ft_init_pos(t_pos *pos, t_list *list);
t_list		*add_elem(char *av, t_list *list, int pos);
t_list		*create_elem(char *av, int i);
void		ft_print_list(t_list *list, int fd);
void		ft_set_limit(t_pos *e);
int			ft_restore_term(t_term term);
int			ft_run(t_pos *e, t_list **list, char *buffer);
t_list      *delete_elem(t_list *list, int pos);
int			ft_delete(t_pos *p, t_list **list);
int			ft_print_select(t_list *list);
int			ft_move_up(t_pos *p, t_list **list);
int			ft_move_down(t_pos *p, t_list **list);
int			ft_return(t_pos *p, t_list **list);
int			ft_escape(t_pos *p, t_list **list);
void        ft_select_signal(void);
void        signal_handler(int sig);
void        ft_ctrl_c(void);
void		ft_ctrl_z(void);
void		ft_fg(void);

#endif
