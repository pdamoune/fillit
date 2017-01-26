/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 11:19:38 by pdamoune          #+#    #+#             */
/*   Updated: 2017/01/26 11:11:17 by pdamoune         ###   ########.fr       */
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
int 	ft_is_tetri(int fd, char **tetris, char **lst_tetri);
int 	ft_solver(char **tetris, char **lst_tetri, char *result, int sqrt_min);

int 	ft_set_sqr(char **tetris, char **lst_tetri, char *result, int sqr_min);
int 	ft_big_sqr(char **tetris, char **lst_tetri, char *result, int sqr_min);
int 	ft_lower_square(char **tetris, char *result, int sqr_min);
int 	ft_init(char **tetris, char **lst_tetri, char *result, int sqr_min);
void 	ft_rem_dot(char *tetri, int sqr_min);
int		ft_test_tetri(char *tmp, char *result, int c);
int		ft_move(char *tetri, char *lst_tetri, int sqr_min);
void	ft_remove_tetri(char *tetri, char *result);



#endif
