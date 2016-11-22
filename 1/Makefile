# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/21 07:12:32 by pdamoune          #+#    #+#              #
#    Updated: 2016/11/22 17:23:24 by pdamoune         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	fillit
SOURCES		=	main.c ft_fillit.c ft_is_tetri.c ft_is_good.c \
$(PATHLIB)/libft.a
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
		ln -s $(PATHLIB) libft

library:
		@make -C libft/

clean:
		rm -rf $(PATHOBJ)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: clean, fclean, re, all, $(NAME), libft
