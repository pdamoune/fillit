# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/05 18:34:34 by pdamoune          #+#    #+#              #
#    Updated: 2017/02/11 16:16:38 by philippedamoune  ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a
SOURCES	=	ft_atoi.c ft_bzero.c ft_count_c_words.c ft_isalnum.c ft_isalpha.c \
ft_isascii.c ft_isblank.c ft_isdigit.c ft_islower.c ft_isprint.c ft_isspace.c \
ft_isupper.c ft_isxdigit.c ft_itoa.c ft_lstadd.c ft_lstdel.c ft_lstdelone.c \
ft_lstiter.c ft_lstmap.c ft_lstnew.c ft_memalloc.c ft_memccpy.c ft_memchr.c \
ft_memcmp.c ft_memcpy.c ft_memdel.c ft_memmove.c ft_memset.c ft_putchar.c \
ft_putchar_fd.c ft_putendl.c ft_putendl_fd.c ft_putnbr.c ft_putnbr_fd.c \
ft_putstr.c ft_putstr_fd.c ft_sort_params.c ft_sqrt.c ft_strcat.c ft_strchr.c \
ft_strclr.c ft_strcmp.c ft_strcpy.c ft_strctrim.c ft_strdel.c ft_strdup.c \
ft_strequ.c ft_striter.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlen.c \
ft_strmap.c ft_strmapi.c ft_strncat.c ft_strncmp.c ft_strncpy.c ft_strnequ.c \
ft_strnew.c ft_strnstr.c ft_strrchr.c ft_strrev.c ft_strsplit.c ft_strstr.c \
ft_strsub.c ft_strtrim.c ft_swap.c ft_tolower.c ft_toupper.c ft_count_occur.c \
ft_conv_bin.c ft_strdift.c ft_sqrt_min.c ft_strcstr.c ft_putnbrel.c \
ft_memrealloc.c ft_lst_find.c
HEADERS	=	libft.h
CFLAGS	=	-Wall -Wextra -Werror
CC		=	clang
PATHSRC =	src
PATHINC	=	include
PATHOBJ	=	obj
OBJETS	=	$(patsubst %.c,$(PATHOBJ)/%.o,$(SOURCES))

all: $(NAME)

$(PATHOBJ)/%.o: $(PATHSRC)/%.c
	@mkdir -p $(PATHOBJ)
	$(CC) $(CFLAGS) -I $(PATHINC) -c $< -o $@

$(NAME): $(OBJETS)
		@ar rc $(NAME) $(OBJETS)
		@ranlib $(NAME)

clean:
		@rm -rf $(PATHOBJ)

fclean: clean
		@rm -f $(NAME)

re: fclean all

.PHONY: clean, fclean, re, all, $(NAME)
