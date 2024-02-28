/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sal-zuba <sal-zuba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 13:08:36 by sal-zuba          #+#    #+#             */
/*   Updated: 2024/02/25 13:08:36 by sal-zuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	my_keyhook(mlx_key_data_t keydata, void *param)
{
	t_general	*g;

	g = (t_general *)param;
	cel_floor(g);
	all(g, g->map->map);
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		ft_fr(g->map, g, 1);
		mlx_terminate(g->mlx);
		exit(0);
	}
	if (mlx_is_key_down(g->mlx, MLX_KEY_RIGHT))
		rotate(g->vectors, 1);
	if (mlx_is_key_down(g->mlx, MLX_KEY_LEFT))
		rotate(g->vectors, -1);
	move(g, g->vectors);
}

void	init(t_general *g, t_map *map)
{
	setup(map, g);
	g->map = map;
	get_player_pos(g, map->map);
	g->mlx = NULL;
	g->img = NULL;
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	g->mlx = mlx_init(1920, 1080, "CUB3D", true);
	if (!g->mlx)
		return ;
	g->img = mlx_new_image(g->mlx, 1920, 1080);
	if (!g->img)
		return ;
	mlx_image_to_window(g->mlx, g->img, 0, 0);
	cel_floor(g);
	all(g, g->map->map);
	mlx_key_hook(g->mlx, &my_keyhook, g);
	mlx_loop(g->mlx);
	mlx_terminate(g->mlx);
}

int32_t	ft_color(int32_t r, int32_t g, int32_t b)
{
	return (r << 24 | g << 16 | b << 8 | 0x000000FF);
}

void	cel_floor(t_general *g)
{
	unsigned int	x;
	unsigned int	y;

	x = -1;
	while (++x < g->img->width)
	{
		y = 0;
		while (y < g->img->height / 2)
			mlx_put_pixel(g->img, x, y++,
				ft_color(g->map->c_c[0], g->map->c_c[1], g->map->c_c[2]));
		while (y < g->img->height - 1)
			mlx_put_pixel(g->img, x, y++,
				ft_color(g->map->f_c[0], g->map->f_c[1], g->map->f_c[2]));
	}
}

void	ft_fr(t_map *map, t_general *g, int flag)
{
	int	i;

	i = -1;
	if (map->everything)
		ft_free_mat(map->everything);
	if (map->map)
		ft_free_mat(map->map);
	i = -1;
	while (++i < 4)
	{
		if (map->textures[i])
			free(map->textures[i]);
	}
	if (flag)
	{
		i = -1;
		while (++i < 4)
			mlx_delete_texture(g->walls[i]);
	}
}
