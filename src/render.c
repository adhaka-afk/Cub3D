/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sal-zuba <sal-zuba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 15:00:20 by sal-zuba          #+#    #+#             */
/*   Updated: 2024/02/27 18:27:19 by sal-zuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	set_textures2(t_texture *t, t_wall *w, t_general *g, t_arrays *arr)
{
	t->height = (g->img->height) / w->wall_dist;
	t->start = (g->img->height / 2) - (t->height / 2);
	t->end = (g->img->height / 2) + (t->height / 2);
	if (t->start < 0)
		t->start = 0;
	if (t->end >= (int)(g->img->height))
		t->end = g->img->height - 1;
	if (w->hit_ax == 0)
		t->wall_x = g->vectors[0].y + (w->wall_dist * arr->d[1]);
	else
		t->wall_x = g->vectors[0].x + (w->wall_dist * arr->d[0]);
}

void	set_textures(t_texture *t, t_wall *w, mlx_texture_t *wall, t_arrays *a)
{
	t->wall_x -= floor(t->wall_x);
	t->pxl[0] = (int)(t->wall_x * (double)wall->width);
	if ((w->hit_ax == 0 && a->d[0] > 0)
		|| (w->hit_ax == 1 && a->d[1] < 0))
		t->pxl[0] = wall->width - t->pxl[0] - 1;
}

void	walls(t_wall *w, short x, t_general *g, t_arrays *arr)
{
	t_texture		t;
	mlx_texture_t	*wall;
	int				pix;
	int				i;

	i = w->wall_hit;
	wall = g->walls[i];
	set_textures2(&t, w, g, arr);
	set_textures(&t, w, wall, arr);
	t.step = (double)(wall->height) / t.height;
	t.pos = (t.start - (g->img->height / 2) + (t.height / 2)) * t.step;
	while (t.start < t.end)
	{
		t.pxl[1] = t.pos;
		pix = (t.pxl[1] * wall->width + t.pxl[0]) * 4;
		mlx_put_pixel(g->img, x, t.start, ft_color(wall->pixels[pix + 0],
				wall->pixels[pix + 1], wall->pixels[pix + 2]));
		t.pos += t.step;
		t.start++;
	}
}

void	rotate(t_vector *vec, short sign)
{
	double	cos_;
	double	sin_;
	double	tmp;

	cos_ = cos(sign * ROT);
	sin_ = sin(sign * ROT);
	tmp = vec[1].x;
	vec[1].x = (vec[1].x * cos_) - (vec[1].y * sin_);
	vec[1].y = (tmp * sin_) + (vec[1].y * cos_);
	tmp = vec[2].x;
	vec[2].x = (vec[2].x * cos_) - (vec[2].y * sin_);
	vec[2].y = (tmp * sin_) + (vec[2].y * cos_);
}

void	move(t_general *g, t_vector *vec)
{
	double		w_x;
	double		w_y;

	w_x = vec[1].x * MV;
	w_y = vec[1].y * MV;
	if (mlx_is_key_down(g->mlx, MLX_KEY_D))
		if (g->map->map[(int)(vec[0].y + w_x)][(int)(vec[0].x - w_y)] != '1')
			vec[0] = (t_vector){vec[0].x - w_y, vec[0].y + w_x};
	if (mlx_is_key_down(g->mlx, MLX_KEY_A))
		if (g->map->map[(int)(vec[0].y - w_x)][(int)(vec[0].x + w_y)] != '1')
			vec[0] = (t_vector){vec[0].x + w_y, vec[0].y - w_x};
	if (mlx_is_key_down(g->mlx, MLX_KEY_W))
		if (g->map->map[(int)(vec[0].y + w_y)][(int)(vec[0].x + w_x)] != '1')
			vec[0] = (t_vector){vec[0].x + w_x, vec[0].y + w_y};
	if (mlx_is_key_down(g->mlx, MLX_KEY_S))
		if (g->map->map[(int)(vec[0].y - w_y)][(int)(vec[0].x - w_x)] != '1')
			vec[0] = (t_vector){vec[0].x - w_x, vec[0].y - w_y};
}
