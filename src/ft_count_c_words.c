/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_c_words.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 16:57:04 by pdamoune          #+#    #+#             */
/*   Updated: 2016/11/17 19:03:31 by philippedamoune  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Permet de compter le nombre de mots dans str, avec comme separateur c.
*/

int		ft_count_c_words(const char *str, char c)
{
	int		words;
	int		i;

	i = 0;
	words = 0;
	while (str[i])
	{
		while (str[i] != c && str[i])
			i++;
		words++;
		while (str[i] == c && str[i])
			i++;
	}
	return (words);
}
