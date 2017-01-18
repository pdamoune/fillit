/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 11:19:38 by pdamoune          #+#    #+#             */
/*   Updated: 2017/01/17 22:56:34 by pdamoune         ###   ########.fr       */
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
char	*ft_parsing(char *str);
void 	ft_test(char **tetris, char **lst_tetri, int sqr_min);
int 	ft_is_tetri(int fd, char **tetris, char **lst_tetri);
int 	ft_solver(char **tetris, char **lst_tetri, int sqrt_min);

void 	ft_set_square(char **tetris, char **lst_tetri, char *result, int sqr_min);
int 	ft_bigger_square(char **tetris, char **lst_tetri, char *result, int sqr_min);
int		ft_test_tetri(char *tmp, char *result);
int		ft_move_tetri(char *tetri, char *lst_tetri, int sqr_min);
void	ft_remove_tetri(char *tetri, char *result);



#endif
