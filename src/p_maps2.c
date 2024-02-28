/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_maps2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adhaka <adhaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 19:50:27 by adhaka            #+#    #+#             */
/*   Updated: 2024/02/28 19:52:14 by adhaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

char	**mapcp(char **map)
{
	int		i;
	char	**tmp;
	int		len;

	len = 0;
	i = -1;
	while (map[++i])
	{
		if (ft_strchr(map[i], '1'))
			len++;
	}
	tmp = (char **)malloc(sizeof(char *) * (len + 1));
	i = -1;
	len = 0;
	while (map[++i])
	{
		if (ft_strchr(map[i], '1'))
		{
			tmp[len] = ft_strdup(map[i]);
			len++;
		}
	}
	tmp[len] = 0;
	return (tmp);
}

int	flood_fill(t_map *map, int y, int x, int flag)
{
	if (flag && (x < 0 || y < 0 || !map->tmp[y]
			|| (size_t)x >= ft_strlen(map->tmp[y]) || !map->tmp[y][x]))
	{
		ft_fr(map, NULL, 0);
		ft_error("Inavlid Map\n");
	}
	if (x < 0 || y < 0 || !map->tmp[y]
		|| (size_t)x >= ft_strlen(map->tmp[y]) || !map->tmp[y][x])
		return (-2);
	if (map->tmp[y][x] == ' ')
	{
		ft_fr(map, NULL, 0);
		ft_error("Inavlid Map\n");
	}
	if (map->tmp[y][x] == '0')
	{
		map->tmp[y][x] = 'P';
		flood_fill(map, y, x + 1, 1);
		flood_fill(map, y, x - 1, 1);
		flood_fill(map, y + 1, x, 1);
		flood_fill(map, y - 1, x, 1);
	}
	return (0);
}

int	check(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '0')
			{
				if (ft_check_borders(map, i, j) == -1)
					return (-1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_check_borders(char **map, int i, int j)
{
	int	flag;

	flag = 0;
	if (map[i][j + 1] != '1' || map[i][j + 1] != '\0')
		flag = 1;
	if (map[i][j - 1] != '1' || map[i][j + 1] != '\0')
		flag = 1;
	if (map[i + 1][j] != '1' || map[i][j + 1] != '\0')
		flag = 1;
	if (map[i - 1][j] != '1' || map[i][j + 1] != '\0')
		flag = 1;
	if (flag)
		return (-1);
	return (0);
}

int	ft_height(char **tmp)
{
	int	i;
	int	len;

	len = 0;
	i = 0;
	while (tmp[i] && tmp[i][0] == '\n')
		i++;
	while (tmp[i++])
		len++;
	return (len);
}
