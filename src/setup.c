/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adhaka <adhaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 13:38:43 by sal-zuba          #+#    #+#             */
/*   Updated: 2024/02/28 20:18:36 by adhaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	setup(t_map	*map, t_general *g)
{
	g->walls[0] = mlx_load_png(map->textures[0]);
	g->walls[1] = mlx_load_png(map->textures[1]);
	g->walls[2] = mlx_load_png(map->textures[2]);
	g->walls[3] = mlx_load_png(map->textures[3]);
}

void	get_player_pos(t_general *g, char **map)
{
	int		x;
	int		y;
	char	flag;

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
				flag = map[y][x];
				g->vectors[0].x = (double)x + 0.5;
				g->vectors[0].y = (double)y + 0.5;
			}
			x++;
		}
		y++;
	}
	get_player_dir(g, flag);
}

void	get_player_dir(t_general *g, char flag)
{
	if (flag == 'N')
	{
		g->vectors[1] = (t_vector){0, -1};
		g->vectors[2] = (t_vector){FOV, 0};
	}
	else if (flag == 'S')
	{
		g->vectors[1] = (t_vector){0, 1};
		g->vectors[2] = (t_vector){FOV * -1, 0};
	}
	else if (flag == 'W')
	{
		g->vectors[1] = (t_vector){1, 0};
		g->vectors[2] = (t_vector){0, FOV};
	}
	else
	{
		g->vectors[1] = (t_vector){-1, 0};
		g->vectors[2] = (t_vector){0, FOV * -1};
	}
}
