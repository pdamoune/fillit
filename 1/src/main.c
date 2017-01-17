/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 08:56:03 by pdamoune          #+#    #+#             */
/*   Updated: 2017/01/17 16:54:29 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"

int	main(int argc, char **argv)
{
	if (argc == 2)
		ft_fillit(argv[1]);
	else
		ft_putendl("usage: ./fillit tetriminos_list_file");
	return(0);
}
