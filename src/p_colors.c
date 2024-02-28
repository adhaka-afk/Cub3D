/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_colors.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adhaka <adhaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 22:02:39 by adhaka            #+#    #+#             */
/*   Updated: 2024/02/28 20:31:19 by adhaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	check_rec(char *f, char *c)
{
	int	flag1;
	int	flag2;
	int	i;

	i = -1;
	flag1 = 0;
	flag2 = 0;
	while (f[++i])
	{
		if (f[i] == ',')
			flag1++;
	}
	i = -1;
	while (c[++i])
	{
		if (c[i] == ',')
			flag2++;
	}
	if (flag1 != 2 || flag2 != 2)
		return (-1);
	return (0);
}

int	fill_colors_f(t_map *map, char *floor)
{
	char	*tmp;
	int		i;
	int		j;
	int		flag;
	int		k;

	k = 0;
	flag = 0;
	j = 0;
	i = -1;
	while (floor[++i] && flag < 2)
	{
		if (floor[i] == ',')
		{
			tmp = ft_substr(floor, j, i - j);
			map->f_c[k] = ft_atoi(tmp);
			free(tmp);
			j = i + 1;
			k++;
			flag++;
		}
	}
	tmp = ft_substr(floor, i, ft_strlen(floor));
	map->f_c[k] = ft_atoi(tmp);
	return (free(tmp), 0);
}

int	fill_colors_c(t_map *map, char *ceiling)
{
	char	*tmp;
	int		i;
	int		j;
	int		flag;
	int		k;

	k = 0;
	flag = 0;
	j = 0;
	i = -1;
	while (ceiling[++i] && flag < 2)
	{
		if (ceiling[i] == ',')
		{
			tmp = ft_substr(ceiling, j, i - j);
			map->c_c[k] = ft_atoi(tmp);
			free(tmp);
			j = i + 1;
			k++;
			flag++;
		}
	}
	tmp = ft_substr(ceiling, i, ft_strlen(ceiling));
	map->c_c[k] = ft_atoi(tmp);
	return (free(tmp), 0);
}

int	check_values(t_map *map)
{
	int	i;

	i = -1;
	while (map->f_c[++i])
	{
		if (map->f_c[i] < 0 || map->f_c[i] > 255)
			return (-1);
	}
	i = -1;
	while (map->c_c[++i])
	{
		if (map->c_c[i] < 0 || map->c_c[i] > 255)
			return (-1);
	}
	return (0);
}

int	get_colors(t_map *map)
{
	int		i;
	char	*floor;
	char	*ceiling;

	i = -1;
	while (map->everything[++i])
	{
		if (ft_strncmp(map->everything[i], "F ", 2) == 0)
			floor = ft_strdup3(map->everything[i] + 2);
		if (ft_strncmp(map->everything[i], "C ", 2) == 0)
			ceiling = ft_strdup3(map->everything[i] + 2);
	}
	if (check_rec(floor, ceiling) == -1)
		return (free(ceiling), free(floor), -1);
	if (check_num_f(floor) == -1 || check_num_c(ceiling) == -1)
		return (free(ceiling), free(floor), -1);
	fill_colors_f(map, floor);
	fill_colors_c(map, ceiling);
	free(ceiling);
	free(floor);
	if (check_values(map) == -1)
		return (-1);
	return (0);
}
