/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adhaka <adhaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 19:17:38 by adhaka            #+#    #+#             */
/*   Updated: 2024/02/28 19:57:02 by adhaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	check_scene(char *cube, t_map *map)
{
	int		size;
	int		i;
	char	*name;
	int		fd;

	i = -1;
	size = map_size(cube);
	name = name_finder(cube);
	map->everything = (char **)malloc(sizeof(char *) * (size + 1));
	fd = open(name, O_RDONLY);
	free(name);
	while (++i < size)
		map->everything[i] = get_next_line(fd);
	map->everything[size] = 0;
	close (fd);
	if (check_ids(map) == -1)
		return (-1);
	if (get_ids(map) == -1)
		return (-1);
	if (check_general(map) == -1)
		return (-1);
	if (get_actual_map(map) == -1)
		return (-1);
	return (0);
}

int	map_size(char *name)
{
	char	*tmp;
	int		i;
	int		fd;

	tmp = (char *)malloc((6 * sizeof(char)));
	tmp = "maps/";
	tmp[5] = '\0';
	tmp = ft_strjoin(tmp, name);
	fd = open(tmp, O_RDONLY);
	free(tmp);
	i = 0;
	while (1)
	{
		tmp = get_next_line(fd);
		if (tmp && ++i > -1)
			free(tmp);
		else
			break ;
	}
	close (fd);
	return (i);
}

int	check_general(t_map *map)
{
	int	i;
	int	flag;
	int	j;

	j = 0;
	flag = 0;
	i = check_last(map);
	while (j <= i)
	{
		while (map->everything[j][0] == '\n')
			j++;
		if (ft_strncmp(map->everything[j], "NO ", 3)
			&& ft_strncmp(map->everything[j], "SO ", 3) != 0
			&& ft_strncmp(map->everything[j], "WE ", 3) != 0
			&& ft_strncmp(map->everything[j], "EA ", 3) != 0
			&& ft_strncmp(map->everything[j], "F ", 2) != 0
			&& ft_strncmp(map->everything[j], "C ", 2) != 0)
			return (-1);
		j++;
	}
	return (flag);
}
