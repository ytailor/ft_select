#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ytailor <ytailor@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/01/01 17:55:58 by ytailor           #+#    #+#              #
#    Updated: 2014/01/12 17:13:24 by ytailor          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = ft_select

FLAG = -Wall -Wextra -Werror

SRCS = main.c ft_list.c ft_init.c ft_select.c ft_select_key.c signal.c

LIBFT = ./libft/includes

OBJS = $(SRCS:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJS) ./ft_select.h
	make -C libft/
	gcc -o $(NAME) $(FLAG) -ltermcap $(OBJS) libft/libft.a


clean:
	make clean -C libft/
	rm -f $(OBJS)

fclean: clean
	make fclean -C libft/
	rm -f $(NAME)

re: fclean all

%.o: %.c
	gcc $(FLAG) -I $(LIBFT) -c $<

.PHONY: all clean fclean re
