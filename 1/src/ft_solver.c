/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solver.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: philippe <philippe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/24 18:39:43 by philippe          #+#    #+#             */
/*   Updated: 2017/01/16 05:54:46 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"
#include <stdio.h>

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
	ft_putendl(result);


}


int 	ft_bigger_sqr(char **tetris, char **lst_tetri, int sqr_min)
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	k = 0;
	// DEB
	// ft_putendl(tetris[0]);
	// ft_putnbr(sqr_min);
	// DEB
	while (tetris[i + 1])
	{

		*ft_strchr(tetris[i], 0) = '.';
		if (j == 0)
			while (tetris[i][j] == '.')
				j++;
		while (k < 4)
		{
			while (ft_isalpha(tetris[i][j++]))
				k++;
			if (k == 4)
			{
				ft_strcpy(lst_tetri[i], tetris[i]);
				tetris[i][sqr_min] = 0;
				*(ft_strrchr(lst_tetri[i], i + 65) + 1) = 0;
				break;
			}
			ft_memmove(&tetris[i][j + 1], &tetris[i][j], sqr_min);
			tetris[i][j] = '.';
			//ft_putendl(tetris[0]);
			while (tetris[i][j] == '.')
				j++;
		}
		k = 0;
		j = 0;
		i++;
	}
	return (0);
}

void 	ft_set_tetri(char **tetris, char **lst_tetri, char *result, int sqr_min)
{
	int i;

	i = 4;

	while (ft_sqrt(sqr_min) > i)
	{
		ft_bigger_sqr(tetris, lst_tetri, (i + 1) * (i + 1));
		i++;
	}
	ft_memset(result, '.', sqr_min);
	result[sqr_min] = 0;
	// 	tetris[i][sqr_min] = 0;
}

int 	ft_setup(char *tmp, char *original, int sqr_min)
{
	int		sqr;
	int 	i;

	sqr = ft_sqrt(sqr_min);
	i = 0;
	while (tmp[i] == '.')
		i++;
	if (i < sqr)
		sqr = 0;
	else
		while (sqr < i)
		{
			sqr += ft_sqrt(sqr_min);
		}
	if (sqr)
		sqr = sqr - ft_sqrt(sqr_min);
	ft_remove_tetri(tmp, tmp);
	ft_strcpy(&tmp[sqr], original);
	*ft_strchr(tmp, '\0') = '.';
	tmp[sqr_min] = 0;
	return (1);
}



int		ft_move_vertical(char *tmp, char *original, int sqr_min)
{
	int		sqr;
	char	tmp2[200];


	sqr = sqr_min - 1;
	ft_setup(tmp, original, sqr_min);
	while (&tmp[sqr_min] - ft_strchr(tmp, '\0'))
		*ft_strchr(tmp, '\0') = '.';
	while (sqr >= sqr_min - ft_sqrt(sqr_min))
	{
		if (tmp[sqr] == '.')
			sqr -= 1;
		else
			return (0);
	}
	ft_strcpy(tmp2, tmp);
	ft_memcpy(&tmp[ft_sqrt(sqr_min)], tmp2, sqr_min - ft_sqrt(sqr_min));

	sqr = ft_sqrt(sqr_min) - 1;
	while (sqr + 1)
		tmp[sqr--] = '.';
	return (1);
}

int		ft_move(char *tmp, char *original, int sqr_min)
{
	int		sqr;
	char	tmp2[200];

	
	sqr = ft_sqrt(sqr_min) - 1;
	if (&tmp[sqr_min] - ft_strchr(tmp, '\0'))
		*ft_strchr(tmp, '\0') = '.';
	while (sqr < sqr_min)
	{
		if (tmp[sqr] == '.')
		{
			sqr += ft_sqrt(sqr_min);
		}
		else if (ft_move_vertical(tmp, original, sqr_min) == 1)
		{
			DEB
			return (1);
		}
		else
		{
			return (0);
		}
	}
	ft_strcpy(tmp2, tmp);
	ft_memcpy(&tmp[1], tmp2, sqr_min - 1);
	tmp[0] = '.';
	// ft_putendl(tmp);
	DEB

	return (1);
}

int		ft_test_tetri(char *tmp, char *result)
{
	int		i;
	int		j;

	i = 0;
	j = 0;

	if (!ft_strdift(result, tmp))
	{
		return (0);
	}
	while (tmp[i])
	{
		if (tmp[i] != '.')
			result[j] = tmp[i];
		i++;
		j++;
	}
	return (1);
}

int		ft_test_combi(char **tetris, char **lst_tetri, char *result, int sqr_min)
{
	static int i = 0;



	while (tetris[i])
	{
		//ft_putnbr(sqr_min), ft_putchar('='), ft_putendl(result);
		if (i == -1)
			return (0);
		if (ft_test_tetri(tetris[i], result) == 1)
		{
			i++;
		}
		else if (ft_move(tetris[i], lst_tetri[i], sqr_min) != 0)
		{
			ft_test_combi(tetris, lst_tetri, result, sqr_min);
		}
		else
		{
			ft_remove_tetri(tetris[--i], result);
			if (ft_move(tetris[i], lst_tetri[i], sqr_min) == 0)
			{
				if (i == 0)
				{
					// ft_putnbr(sqr_min), ft_putendl(result);
					// ft_putendl(tetris[1]);
					sqr_min = (ft_sqrt(sqr_min) + 1) * (ft_sqrt(sqr_min) + 1);
					// ft_putnbr(sqr_min);
					ft_test(tetris, lst_tetri, sqr_min);
					ft_bigger_sqr(tetris, lst_tetri, sqr_min);
					ft_memset(result, '.', sqr_min);
					result[sqr_min] = 0;
					// ft_putendl(tetris[1]);
					ft_test_combi(tetris, lst_tetri, result, sqr_min);
				}
				else
				{
					ft_test(&tetris[i], &lst_tetri[i], sqr_min);
					ft_remove_tetri(tetris[--i], result);
					ft_move(tetris[i], lst_tetri[i], sqr_min);
					ft_test_combi(tetris, lst_tetri, result, sqr_min);
				}
			}
		}
	}
	return (1);
}

int		ft_solver(char **tetris, char **lst_tetri, int sqr_min)
{
	// char	tmp[sqr_min + 1];
	char	result[196];
	int		i;
	int		j;

	i = 0;
	j = 0;
	ft_bzero(result, 197);
	ft_memset(result, '.', 196);
	i = 0;
	while (*lst_tetri[i])
		printf("lst = %s\n", lst_tetri[i++]);
	i = 0;
	ft_putendl("");
	while (*tetris[i])
		printf("lst = %s\n", tetris[i++]);
	// ft_putendl(result);
	ft_putendl("");
	ft_set_tetri(tetris, lst_tetri, result, sqr_min);
	i = 0;
	// exit (0);
	ft_test_combi(tetris, lst_tetri, result, sqr_min);

	// if (ft_test_combi(tetris, lst_tetri, result, sqr_min) == 0)
	// 	sqr_min = (ft_sqrt(sqr_min) + 1) * (ft_sqrt(sqr_min) + 1);
	// ft_set_tetri(tetris, lst_tetri, result, sqr_min);
		// ft_test(tetris, lst_tetri);
	// if (j == 0)
	// 	ft_bigger_sqr(tetris, lst_tetri, 25);
	DEB
	ft_putendl("");

	i = 0;
	while (*lst_tetri[i])
		printf("lst = %p\n", lst_tetri[i++]);
	i = 0;

	while (*tetris[i])
		printf("lst = %p\n", tetris[i++]);
	i = 0;
	ft_putendl("");

	DEB

	ft_putnbr(sqr_min);
	ft_putendl("");

	while (i < (int)ft_strlen(result))
	{
		if (i % ft_sqrt(ft_strlen(result)) == 0)
			ft_putchar('\n');
		ft_putchar(result[i]);
		i++;
	}
	ft_putchar('\n');
	ft_putchar('\n');
	return(0);
}
