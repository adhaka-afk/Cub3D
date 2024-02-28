/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sal-zuba <sal-zuba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 13:08:45 by sal-zuba          #+#    #+#             */
/*   Updated: 2024/02/27 18:30:35 by sal-zuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	make_ray(t_arrays *arr, t_vector *vec, double a)
{
	arr->d[0] = vec[1].x + (vec[2].x * a);
	arr->d[1] = vec[1].y + (vec[2].y * a);
	arr->d[2] = fabs(1 / arr->d[0]);
	arr->d[3] = fabs(1 / arr->d[1]);
	arr->s[0] = vec[0].x;
	arr->s[1] = vec[0].y;
}

void	all(t_general *g, char **map)
{
	t_arrays		arr;
	uint32_t		x;
	uint32_t		width;
	t_wall			w;

	width = g->img->width;
	x = -1;
	while (++x < width)
	{
		make_ray(&arr, g->vectors, (2 * x / (double)width - 1));
		if (arr.d[0] < 0)
			set_values(&arr, g->vectors);
		else
			set_values2(&arr, g->vectors);
		if (arr.d[1] < 0)
			set_values3(&arr, g->vectors);
		else
			set_values4(&arr, g->vectors);
		w.hit_ax = hit_ax(&arr, map);
		dist_hit(&arr, &w);
		walls(&w, x, g, &arr);
	}
}

void	dist_hit(t_arrays *arr, t_wall *w)
{
	if (w->hit_ax == 0)
	{
		w->wall_dist = arr->d[4] - arr->d[2];
		w->wall_hit = arr->s[4];
	}
	else
	{
		w->wall_dist = arr->d[5] - arr->d[3];
		w->wall_hit = arr->s[5];
	}
}
