/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_maps3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adhaka <adhaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 19:51:04 by adhaka            #+#    #+#             */
/*   Updated: 2024/02/28 20:14:00 by adhaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	get_p_pos(t_map *maps, char **map)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'N' || map[y][x] == 'S'
					|| map[y][x] == 'W' || map[y][x] == 'E')
			{
				maps->p[0] = y;
				maps->p[1] = x;
				break ;
			}
			x++;
		}
		y++;
	}
}

int	get_actual_map(t_map *map)
{
	int		i;
	char	**tmp;

	i = check_last(map);
	ft_copy_map(map, i);
	i = 0;
	if (check_start(map->map) == -1)
		return (-1);
	tmp = mapcp(map->map);
	get_p_pos(map, tmp);
	tmp[map->p[0]][map->p[1]] = '0';
	map->tmp = tmp;
	flood_fill(map, map->p[0], map->p[1], 0);
	ft_free_mat(map->tmp);
	return (0);
}
