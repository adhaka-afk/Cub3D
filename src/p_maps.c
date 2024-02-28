/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_maps.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adhaka <adhaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 22:04:50 by adhaka            #+#    #+#             */
/*   Updated: 2024/02/28 20:09:22 by adhaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	ft_compare(int *j)
{
	int	i;
	int	res;

	i = 0;
	res = j[0];
	while (i < 6)
	{
		if (res < j[i])
			res = j[i];
		i++;
	}
	return (res);
}

int	check_last(t_map *map)
{
	int	*j;
	int	i;

	j = (int *)malloc(sizeof(int) * 7);
	i = -1;
	while (map->everything[++i])
	{
		if (ft_strncmp(map->everything[i], "NO ", 3) == 0)
			j[0] = i;
		if (ft_strncmp(map->everything[i], "SO ", 3) == 0)
			j[1] = i;
		if (ft_strncmp(map->everything[i], "WE ", 3) == 0)
			j[2] = i;
		if (ft_strncmp(map->everything[i], "EA ", 3) == 0)
			j[3] = i;
		if (ft_strncmp(map->everything[i], "F ", 2) == 0)
			j[4] = i;
		if (ft_strncmp(map->everything[i], "C ", 2) == 0)
			j[5] = i;
	}
	i = ft_compare(j);
	free(j);
	return (i);
}

int	check_e(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n' || str[i] == '\t' || str[i] == ' ')
			i++;
		else
			return (1);
	}
	return (0);
}

void	ft_copy_map(t_map *map, int start)
{
	int	len;
	int	i;

	i = 0;
	len = 0;
	while (map->everything[len])
		len++;
	map->map = malloc(sizeof(char *) * (len - start));
	start++;
	while (map->everything[start])
	{
		map->map[i] = ft_strdup(map->everything[start]);
		i++;
		start++;
	}
	map->map[i] = 0;
}

int	check_start(char **map)
{
	int	s_count;
	int	row;
	int	col;

	s_count = 0;
	row = 0;
	col = 0;
	while (map[row])
	{
		col = 0;
		while (map[row][col])
		{
			if (map[row][col] == 'N' || map[row][col] == 'S' ||
				map[row][col] == 'E' || map[row][col] == 'W')
				s_count++;
			col++;
		}
		row++;
	}
	if (s_count != 1)
		return (-1);
	return (0);
}
