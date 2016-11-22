# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile~                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgengo <jgengo@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/18 14:05:46 by jgengo            #+#    #+#              #
#    Updated: 2016/11/18 16:40:33 by jgengo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= fillit

CC				= gcc
CFLAGS			= -Wall -Wextra -Werror

SRCS			= srcs/checkfile.c \
				  srcs/errors.c \
				  srcs/fillit.c \
				  srcs/init_game.c \
				  srcs/solve.c \
				  srcs/storeblock.c 

OBJS = $(subst .c,.o,$(subst srcs/,,$(SRCS)))



all: $(NAME)

$(NAME): lib $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L libft -lft

$(OBJS):
	$(CC) $(CFLAGS) -c $(SRCS) -Iincludes/ -Ilibft/includes/

lib:
	make -C libft

clean:
	/bin/rm -rf $(OBJS)
	make -C libft clean

fclean: clean
	/bin/rm -rf $(NAME)
	make -C libft fclean

re: fclean all

.PHONY: clean fclean all re
