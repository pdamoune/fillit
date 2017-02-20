/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_bin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 17:02:40 by pdamoune          #+#    #+#             */
/*   Updated: 2017/02/20 07:04:56 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char		*ft_conv_bin(char *str, int b_one, int b_zero)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == b_zero)
			str[i] = 48;
		if (str[i] == b_one)
			str[i] = 49;
		i++;
	}
	return (str);
}
