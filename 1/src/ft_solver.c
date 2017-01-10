/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solver.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: philippe <philippe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/24 18:39:43 by philippe          #+#    #+#             */
/*   Updated: 2017/01/10 17:24:16 by pdamoune         ###   ########.fr       */
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
	if (&tmp[sqrt_min] - ft_strchr(tmp, '\0'))
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
			sqr += ft_sqrt(sqrt_min);
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

int		ft_test_combi(char *tetri, char *tmp, char *result, int sqrt_min)
{
	// ft_putendl(tmp);

// printf("tmp    = %s\nresult = %s\n\n", tmp, result);
// printf("tmp    = %s\ntetri  = %s\nresult = %s\n\n", tmp, tetri, result);


	// if (!ft_stristr(result, tmp, '.') && )
	// 	ft_strcpy(tmp, tetri);
	//printf("tmp    = %s\ntetri  = %s\nresult = %s\n\n", tmp, tetri, result);
	// printf("tmp    = %s\ntetri  = %s\nresult = %s\n\n", tmp, tetri, result);

	if (ft_test_tetri(tmp, result) == 1)
		return (1);
	while (ft_move(tmp, sqrt_min) != 0)
	{
		if (ft_test_tetri(tmp, result) == 0)
			printf("tmp    = %s\ntetri  = %s\nresult = %s\n\n", tmp, tetri, result);
		// if (ft_test_combi(tetri, tmp, result, sqrt_min) == 1)
		// 	return (1);
		else
		{
			// printf("tmp    = %s\ntetri  = %s\nresult = %s\n\n", tmp, tetri, result);


			return (0);
		}
	}
	ft_remove_tetri(tetri, result);
	ft_reset_tetri(tmp, sqrt_min);
	ft_move(tetri, sqrt_min);
	// if (ft_test_combi(tmp, tetri, result, sqrt_min) == 1)
		// return (1);
	// ft_strcpy(tetri, tmp);
	printf("tmp    = %s\ntetri  = %s\nresult = %s\n\n", tmp, tetri, result);
	return (0);
}
//
// else if (ft_test_combi(tetri, tmp, result, sqrt_min) == 0)
// {
//

int		ft_solver(char **lst_tetri, int sqrt_min)
{
	char	tmp[sqrt_min + 1];
	char	tmp2[sqrt_min + 1];
	char	result[sqrt_min + 1];
	int		i;
	int		j;

	i = 0;
	j = 0;
	ft_bzero(result, sqrt_min + 1);
	ft_memset(result, '.', sqrt_min);
	while (lst_tetri[i][0])
	{
		ft_bzero(tmp, sqrt_min + 1);
		ft_memset(tmp, '.', sqrt_min);
		ft_strcpy(tmp, lst_tetri[i]);
		ft_bzero(tmp2, sqrt_min + 1);
		ft_memset(tmp2, '.', sqrt_min);
		ft_strcpy(tmp2, lst_tetri[i - 1]);
		// ft_putstr("tmp    = "), ft_putendl(tmp);
		ft_test_combi(tmp2, tmp, result, sqrt_min);
		ft_putendl("=====================");
		// ft_memset(result, '.', sqrt_min + 1);
		// ft_move(lst_tetri[0], sqrt_min);
		// ft_putendl("");

		i++;
	}
	return(0);
}
