/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 11:19:38 by pdamoune          #+#    #+#             */
/*   Updated: 2017/01/15 19:06:20 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <unistd.h>
# include <fcntl.h>
# include "../libft/include/libft.h"
# include "struct.h"
#define DEB ft_putendl("======test======");

void	ft_fillit();
void 	ft_test(char **tetris, char **lst_tetri, int sqr_min);
int 	ft_is_tetri(int fd, char **tetris, char **lst_tetri);
int 	ft_solver(char **tetris, char **lst_tetri, int sqrt_min);
int		ft_get_next_line(int fd, char *line);
char	*ft_parsing(char *str);

#endif
