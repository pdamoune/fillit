# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/21 07:12:32 by pdamoune          #+#    #+#              #
#    Updated: 2016/11/23 21:56:57 by pdamoune         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	fillit
SOURCES		=	main.c ft_fillit.c ft_is_tetri.c ft_is_good.c ft_struct.c \
ft_displaytetri.c ft_move_tetri.c ft_move_block.c $(PATHLIB)/libft.a
HEADERS		=	libft.h fillit.h
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
		./fillit extern_file.txt


lib:
		ln -s ~/Documents/42/projets_42/library libft

library:
		@make -C libft/

clean:
		rm -rf $(PATHOBJ)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: clean, fclean, re, all, $(NAME), libft
