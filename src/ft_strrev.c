/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 15:25:37 by pdamoune          #+#    #+#             */
/*   Updated: 2016/11/21 03:50:44 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Inverse la chaine de caractere str
*/

char	*ft_strrev(char *str)
{
	int		n;
	int		m;
	char	rev;

	m = 0;
	n = 0;
	while (str[m])
		m++;
	m--;
	while (n < m)
	{
		rev = str[m];
		str[m] = str[n];
		str[n] = rev;
		n++;
		m--;
	}
	return (str);
}
