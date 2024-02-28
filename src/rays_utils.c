/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sal-zuba <sal-zuba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 17:13:55 by sal-zuba          #+#    #+#             */
/*   Updated: 2024/02/27 18:28:47 by sal-zuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	set_values(t_arrays *arr, t_vector *vec)
{
	arr->s[2] = -1;
	arr->d[4] = (vec[0].x - arr->s[0]) * arr->d[2];
	arr->s[4] = 3;
}

void	set_values2(t_arrays *arr, t_vector *vec)
{
	arr->s[2] = 1;
	arr->d[4] = (arr->s[0] + 1.0 - vec[0].x) * arr->d[2];
	arr->s[4] = 2;
}

void	set_values3(t_arrays *arr, t_vector *vec)
{
	arr->s[3] = -1;
	arr->d[5] = (vec[0].y - arr->s[1]) * arr->d[3];
	arr->s[5] = 0;
}

void	set_values4(t_arrays *arr, t_vector *vec)
{
	arr->s[3] = 1;
	arr->d[5] = (arr->s[1] + 1.0 - vec[0].y) * arr->d[3];
	arr->s[5] = 1;
}

int	hit_ax(t_arrays *arr, char **map)
{
	int	ax;

	ax = 0;
	while (true)
	{
		if (arr->d[4] < arr->d[5])
		{
			arr->d[4] += arr->d[2];
			arr->s[0] += arr->s[2];
			ax = 0;
		}
		else
		{
			arr->d[5] += arr->d[3];
			arr->s[1] += arr->s[3];
			ax = 1;
		}
		if (map[arr->s[1]][arr->s[0]] == '1')
			break ;
	}
	return (ax);
}
