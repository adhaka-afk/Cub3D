/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adhaka <adhaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 19:54:11 by adhaka            #+#    #+#             */
/*   Updated: 2024/02/28 01:12:37 by adhaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

char	*ft_strdup3(char *s)
{
	int		i;
	char	*dup;
	int		j;

	i = 0;
	j = ft_strlen(s);
	dup = (char *)malloc((j * sizeof(char) + 1));
	if (dup == 0)
		return (0);
	while (s[i] && s[i] != '\n')
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	*name_finder(char *str)
{
	char	*tmp;
	char	*tmp2;

	tmp = ft_strdup("maps/");
	tmp2 = ft_strjoin(tmp, str);
	free(tmp);
	return (tmp2);
}

int	check_ids(t_map *map)
{
	int	i;
	int	flag;

	flag = 0;
	i = 0;
	while (map->everything[i])
	{
		if (ft_strncmp(map->everything[i], "NO", 2) == 0)
			flag++;
		if (ft_strncmp(map->everything[i], "SO", 2) == 0)
			flag++;
		if (ft_strncmp(map->everything[i], "WE", 2) == 0)
			flag++;
		if (ft_strncmp(map->everything[i], "EA", 2) == 0)
			flag++;
		if (ft_strncmp(map->everything[i], "F", 1) == 0)
			flag++;
		if (ft_strncmp(map->everything[i], "C", 1) == 0)
			flag++;
		i++;
	}
	if (flag == 6)
		return (0);
	else
		return (-1);
}
