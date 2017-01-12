/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solver.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: philippe <philippe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/24 18:39:43 by philippe          #+#    #+#             */
/*   Updated: 2017/01/12 06:34:49 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"

int 	ft_setup(char *tmp, int sqr_min)
{
	int		sqr;
	int 	i;

	sqr = ft_sqrt(sqr_min);
	i = 0;
	if (tmp[0] == '.')
		while (sqr < sqr_min)
		{
			if (tmp[sqr] == '.')
				sqr += ft_sqrt(sqr_min);
			else
				return (0);
		}
	if (sqr == sqr_min)
		ft_strcpy(tmp, &tmp[1]);
	return (1);
}



int		ft_move_vertical(char *tmp, int sqr_min)
{
	int		sqr;

	sqr = sqr_min - 1;
	ft_setup(tmp, sqr_min);
	while (&tmp[sqr_min] - ft_strchr(tmp, '\0'))
		*ft_strchr(tmp, '\0') = '.';
	while (sqr >= sqr_min - ft_sqrt(sqr_min))
	{
		if (tmp[sqr] == '.')
			sqr -= 1;
		else
			return (0);
	}
	ft_memmove(&tmp[ft_sqrt(sqr_min)], tmp, sqr + 1);
	sqr = ft_sqrt(sqr_min) - 1;
	while (sqr + 1)
		tmp[sqr--] = '.';
	return (1);
}

int		ft_move(char *tmp, int sqr_min)
{
	int		sqr;

	sqr = ft_sqrt(sqr_min) - 1;
	if (&tmp[sqr_min] - ft_strchr(tmp, '\0'))
		*ft_strchr(tmp, '\0') = '.';
	while (sqr < sqr_min)
	{
		if (tmp[sqr] == '.')
			sqr += ft_sqrt(sqr_min);
		else if (ft_move_vertical(tmp, sqr_min) == 1)
			return (1);
		else
			return (0);
	}
	ft_memmove(&tmp[1], tmp, sqr_min - 1);
	tmp[0] = '.';
	return (1);
}

int		ft_test_tetri(char *tmp, char *result)
{
	int		i;
	int		j;

	i = 0;
	j = 0;

	// printf("tmp    = %s\nresult = %s\n\n", tmp, result);
	if (!ft_strdift(result, tmp))
		return (0);
	while (tmp[i])
	{
		if (tmp[i] != '.')
			result[j] = tmp[i];
		i++;
		j++;
	}
	return (1);
}

void	ft_remove_tetri(char *tetri, char *result)
{
	int		i;

	i = 0;
	while (tetri[i])
	{
		if (result[i] == tetri[i])
			result[i] = '.';
		i++;
	}
}


int		ft_test_combi(char **tetris, char **lst_tetri, char *result, int sqr_min)
{
	static int i = 0;

	while (tetris[i])
	{
		if (i == -1)
			return (0);
		if (tetris[i + 1])
			ft_test(&tetris[i + 1], &lst_tetri[i + 1]);
		if (ft_test_tetri(tetris[i], result) == 1)
			i++;
		else if (ft_move(tetris[i], sqr_min) != 0)
			ft_test_combi(tetris, lst_tetri, result, sqr_min);
		else
		{
			ft_remove_tetri(tetris[--i], result);
			if (ft_move(tetris[i], sqr_min) == 0)
			{
				ft_test(&tetris[i], &lst_tetri[i]);
				ft_remove_tetri(tetris[--i], result);
				ft_move(tetris[i], sqr_min);
				ft_test_combi(tetris, lst_tetri, result, sqr_min);
			}
		}
	}
	return (1);
}

void 	ft_set_tetri(char **tetris, char **lst_tetri, char *result, int sqr_min)
{
	int i;

	i = 0;
	if (i == 1)
	{
		ft_putendl(result);
		ft_putendl(lst_tetri[0]);
		ft_putnbr(sqr_min);
	}
	while (tetris[i])
		i++;
	// 	tetris[i][sqr_min] = 0;
}

int 	ft_bigger_sqr(char **tetris, char **lst_tetri, int sqr_min)
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	k = 0;
	ft_putnbr(lst_tetri[0][0]);
	ft_putendl("");
	while (tetris[i + 1])
	{
		*ft_strchr(tetris[i], 0) = '.';
		while (k < 4)
		{
			while (ft_isalpha(tetris[i][j]))
			{
				j++;
				k++;
			}
			if (k == 4)
			{
				tetris[i][sqr_min] = 0;
				ft_strcpy(lst_tetri[i], tetris[i]);
				lst_tetri[i][j] = 0;
				break;
			}
			ft_putnbr(sqr_min);
			ft_putendl(tetris[i]);
			ft_memmove(&tetris[i][j + 1], &tetris[i][j], sqr_min);
			while (tetris[i][j] == '.')
				j++;
		}
		k = 0;
		j = 0;

		i++;
	}
	return (0);
}

int		ft_solver(char **tetris, char **lst_tetri, int sqr_min)
{
	// char	tmp[sqr_min + 1];
	char	result[sqr_min + 1];
	int		i;
	int		j;

	i = 0;
	j = 0;
	ft_bzero(result, sqr_min + 1);
	ft_memset(result, '.', sqr_min);
	i = 0;
	while (lst_tetri[i])
		ft_putendl(lst_tetri[i++]);
	i = 0;

	while (tetris[i])
		ft_putendl(tetris[i++]);
	DEB
	// ft_putendl(result);
	ft_set_tetri(tetris, lst_tetri, result, sqr_min);
	ft_test_combi(tetris, lst_tetri, result, sqr_min);
	ft_test(tetris, lst_tetri);
	ft_bigger_sqr(tetris, lst_tetri, 25);
	i = 0;
	while (lst_tetri[i])
		ft_putendl(lst_tetri[i++]);
	i = 0;
	while (tetris[i])
		ft_putendl(tetris[i++]);
	i = 0;
	while (result[i])
	{
		if (i % 4 == 0)
			ft_putchar('\n');
		ft_putchar(result[i]);
		i++;
	}
	return(0);
}
