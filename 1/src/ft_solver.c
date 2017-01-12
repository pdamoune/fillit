/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solver.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: philippe <philippe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/24 18:39:43 by philippe          #+#    #+#             */
/*   Updated: 2017/01/12 04:02:46 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"
#include <stdio.h>

// void 	ft_move_tetri(char *tetri, int sqrt_min)
// {
	/*

	ft_memmove(&tetri[1], &tetri[0], sqrt_min - 1);
	tetri[0] = '.';
	if (tetri[sqrt_min - 1] != '\0')
 		ft_putendl(tetri);

	*/

// }

char	*ft_stristr(const char *haystack, const char *needle, int c)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	c = 1;
	while (haystack[i])
	{
		while (needle[j] == haystack[i + j] || needle[j] == '.')
		{
			if (needle[j + 1] == '\0')
			{
				return ((char *)&haystack[i]);
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

void	ft_setup(char *tmp)
{
	while (tmp[0] == '.' && tmp[4] == '.' && tmp[8] == '.'
		&& !ft_isalpha(tmp[12]))
			ft_strcpy(tmp, tmp + 1);
}

int		ft_move_vertical(char *tmp, int sqrt_min)
{
	int		sqr;

	ft_setup(tmp);
	sqr = sqrt_min - 1;
	while (&tmp[sqrt_min] - ft_strchr(tmp, '\0'))
		*ft_strchr(tmp, '\0') = '.';
	while (sqr >= sqrt_min - ft_sqrt(sqrt_min))
	{
		if (tmp[sqr] == '.')
			sqr -= 1;
		else
			return (0);
	}
	ft_memmove(&tmp[ft_sqrt(sqrt_min)], tmp, sqr + 1);
	sqr = ft_sqrt(sqrt_min) - 1;
	while (sqr + 1)
		tmp[sqr--] = '.';
	return (1);
}

int		ft_move(char *tmp, int sqrt_min)
{
	int		sqr;

	sqr = ft_sqrt(sqrt_min) - 1;
	if (&tmp[sqrt_min] - ft_strchr(tmp, '\0'))
		*ft_strchr(tmp, '\0') = '.';
	while (sqr < sqrt_min)
	{
		if (tmp[sqr] == '.')
		{
			sqr += ft_sqrt(sqrt_min);
		}
		else if (ft_move_vertical(tmp, sqrt_min) == 1)
		{
			return (1);
		}
		else
		{
			return (0);
		}
	}

	ft_memmove(&tmp[1], tmp, sqrt_min - 1);
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

void	ft_reset_tetri(char *tmp, int sqrt_min)
{
	int	i;
	int count;

	i = 0;
	count = ft_sqrt(sqrt_min);
	ft_setup(tmp);
	while (tmp)
	{
		while (i < count)
		{
			if (tmp[i] != '.')
				return;
			i++;
		}
		ft_memmove(tmp, &tmp[count], sqrt_min);
		i = 0;
	}

}

int		ft_test_combi(char **tetris, char **lst_tetri, char *result, int sqrt_min)
{
	static int i = 0;

	if (sqrt_min == 1)
		ft_putendl(lst_tetri[0]);
	ft_putendl(result);
	while (tetris[i])
	{
		if (tetris[i + 1])
			ft_test(&tetris[i + 1], &lst_tetri[i + 1]);
		// ft_putendl(result);
		if (ft_test_tetri(tetris[i], result) == 1)
			i++;
		else if (ft_move(tetris[i], sqrt_min) != 0)
		{
			ft_test_combi(tetris, lst_tetri, result, sqrt_min);
		}
		else
		{
			i--;
			ft_remove_tetri(tetris[i], result);
			if (ft_move(tetris[i], sqrt_min) == 0)
			{
				ft_test(&tetris[i], &lst_tetri[i]);
				i--;
				ft_remove_tetri(tetris[i], result);
				ft_move(tetris[i], sqrt_min);
				ft_test_combi(tetris, lst_tetri, result, sqrt_min);
			}
			// exit(0);
		}




	}

	return (1);
}
//
// else if (ft_test_combi(tetri, tmp, result, sqrt_min) == 0)
// {
//

int		ft_solver(char **tetris, char **lst_tetri, int sqrt_min)
{
	// char	tmp[sqrt_min + 1];
	char	result[sqrt_min + 1];
	int		i;
	int		j;

	i = 0;
	j = 0;
	ft_bzero(result, sqrt_min + 1);
	ft_memset(result, '.', sqrt_min);
	i = 0;
	while (lst_tetri[i])
		ft_putendl(lst_tetri[i++]);
	i = 0;
	while (tetris[i])
		ft_putendl(tetris[i++]);
	DEB
	// ft_putendl(result);
	ft_test_combi(tetris, lst_tetri, result, sqrt_min);
	i = 0;
	while (result[i])
	{
		if (i % 4 == 0)
			ft_putchar('\n');
		ft_putchar(result[i]);
		i++;
	}
	// ft_putendl(result);
	// while (tetris[i])
	// 	ft_putendl(tetris[i++]);
	// while (lst_tetri[i][0])
	// {
	// 	ft_bzero(tmp, sqrt_min + 1);
	// 	ft_memset(tmp, '.', sqrt_min);
	// 	ft_strcpy(tmp, lst_tetri[i]);
	// 	ft_putendl(tmp);
	// 	// ft_putstr("tmp    = "), ft_putendl(tmp);
	// 	//ft_test_combi(tmp, tmp, result, sqrt_min);
	// 	{
	// 		// printf("tmp    = %s\nresult = %s\n\n", tmp, result);
	//
	// 		// ft_remove_tetri(tmp, result);
	// 		// ft_reset_tetri(tmp, sqrt_min);
	// 		// ft_move(tmp, sqrt_min);
	// 	}
	// 	ft_putendl("=====================");
	// 	// ft_memset(result, '.', sqrt_min + 1);
	// 	// ft_move(lst_tetri[0], sqrt_min);
	// 	// ft_putendl("");
	//
	// 	i++;
	// }
	return(0);
}
