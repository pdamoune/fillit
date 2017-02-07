# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/21 07:12:32 by pdamoune          #+#    #+#              #
#    Updated: 2017/01/24 12:21:12 by pdamoune         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	fillit
SOURCES		=	main.c ft_fillit.c ft_is_tetri.c ft_parsing.c \
ft_solver.c ft_set_sqr.c ft_big_sqr.c ft_low_sqr.c ft_init.c \
ft_test_tetri.c ft_move_tetri.c ft_remove_tetri.c ft_rem_dot.c \
$(PATHLIB)/libft.a
PATHLIB		=	libft
PATHSRC 	=	src
PATHINC		=	include
HEADERS		=	-I $(PATHINC) -I $(PATHLIB)/$(PATHINC)
CFLAGS		=	-Wall -Wextra -Werror
CC			=	clang
OBJETS		=	$(patsubst %.c,$(PATHSRC)/%.c,$(SOURCES))

all: $(NAME)

$(NAME): library
		@$(CC) $(CFLAGS) -o $(NAME) $(OBJETS) $(HEADERS)

lib:
		rm -rf libft
		ln -s ~/Documents/42/projets_42/library libft

library:
		@make -C libft/

clrlib:
		@make fclean -C libft/

clean:
		@make clean -C libft/
		rm -rf $(PATHOBJ)

fclean: clean
		@make fclean -C libft/
		rm -f $(NAME)

re: fclean all

.PHONY: clean, fclean, re, all, libft
