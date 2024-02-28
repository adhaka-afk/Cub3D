/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adhaka <adhaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 13:59:45 by sal-zuba          #+#    #+#             */
/*   Updated: 2024/02/28 20:47:59 by adhaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	initiate_cube(char *cube, t_map *scene_data)
{
	if (check_scene(cube, scene_data) == -1)
		return (-1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_map		map;
	t_general	g;

	if (argc != 2)
		ft_error("Need to provide only one argument in .cub\n");
	else
	{
		if (is_vext(argv[1], ".cub") != 0)
			ft_error("Not a .cub file \n");
		if (r_eadable(argv[1]) != 0)
			ft_error("Scene not readable.\n");
		if (initiate_cube(argv[1], &map) == -1)
			ft_error("Parsing error\n");
	}
	init(&g, &map);
	ft_fr(&map, &g, 1);
	return (0);
}
