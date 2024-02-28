/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_ids.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sal-zuba <sal-zuba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 22:07:19 by adhaka            #+#    #+#             */
/*   Updated: 2024/02/28 19:44:14 by sal-zuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	check_path(char	**textures)
{
	int				i;
	mlx_texture_t	*tmp;

	i = -1;
	while (textures[++i])
	{
		tmp = mlx_load_png(textures[i]);
		if (!tmp)
			return (-1);
		mlx_delete_texture(tmp);
	}
	return (0);
}

int	get_ids(t_map *map)
{
	int	i;

	i = -1;
	while (map->everything[++i])
	{
		if (ft_strncmp(map->everything[i], "NO ", 3) == 0)
			map->textures[0] = ft_strdup3(map->everything[i] + 3);
		if (ft_strncmp(map->everything[i], "SO ", 3) == 0)
			map->textures[1] = ft_strdup3(map->everything[i] + 3);
		if (ft_strncmp(map->everything[i], "WE ", 3) == 0)
			map->textures[2] = ft_strdup3(map->everything[i] + 3);
		if (ft_strncmp(map->everything[i], "EA ", 3) == 0)
			map->textures[3] = ft_strdup3(map->everything[i] + 3);
	}
	if (get_colors(map) == -1)
		return (-1);
	if (check_path(map->textures) == -1)
		return (-1);
	return (0);
}
