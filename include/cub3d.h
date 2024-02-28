/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adhaka <adhaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 13:58:09 by sal-zuba          #+#    #+#             */
/*   Updated: 2024/02/28 20:32:27 by adhaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "../lib/MLX42/include/MLX42/MLX42.h"
# include "../libft/libft.h"
# include <math.h>

# define FOV 0.66
# define ROT 0.04
# define MV 0.04

typedef struct s_vector
{
	double	x;
	double	y;
}	t_vector;

typedef struct s_map
{
	char	**everything;
	char	**map;
	int		f_c[3];
	int		c_c[3];
	int		p[2];
	char	**tmp;
	char	*textures[4];
}	t_map;

typedef struct s_general
{
	t_vector		vectors[3];
	mlx_t			*mlx;
	mlx_image_t		*img;
	mlx_texture_t	*walls[4];
	t_map			*map;
}		t_general;

typedef struct s_arrays
{
	double	d[6];
	int		s[6];
}	t_arrays;

typedef struct s_wall
{
	double	wall_dist;
	int		wall_hit;
	int		hit_ax;
}	t_wall;

typedef struct s_texture
{
	int		height;
	int		start;
	int		end;
	double	wall_x;
	double	step;
	int		pxl[2];
	double	pos;
}	t_texture;

// main.c
int		initiate_cube(char *cube, t_map *scene_data);

// main_utils.c
int		is_vext(char *f_name, char *str);
void	ft_error(char *str);
int		r_eadable(char *f_name);

// p_colors.c
int		check_rec(char *f, char *c);
int		fill_colors_f(t_map *map, char *floor);
int		fill_colors_c(t_map *map, char *ceiling);
int		check_values(t_map *map);
int		get_colors(t_map *map);
int		not_num(char *str, int start, int end);
int		check_num_c(char *c);
int		check_num_f(char *f);

// p_ids.c
int		check_path(char	**textures);
int		get_ids(t_map *map);

// p_maps.c
int		ft_compare(int *j);
int		get_actual_map(t_map *map);
int		check_last(t_map *map);
void	ft_copy_map(t_map *map, int start);
int		check_start(char **map);
void	get_p_pos(t_map *maps, char **map);
int		flood_fill(t_map *map, int y, int x, int flag);
int		ft_check_borders(char **map, int i, int j);
int		check(char **map);
int		ft_height(char **tmp);
int		check_general(t_map *map);
char	**mapcp(char **map);

//parsing_utils.c
char	*ft_strdup3(char *s);
char	*name_finder(char *str);
int		check_ids(t_map *map);

//parsing.c
int		check_scene(char *cube, t_map *map);
int		map_size(char *name);

//rays_utils.c
void	set_values(t_arrays *arr, t_vector *vec);
void	set_values2(t_arrays *arr, t_vector *vec);
void	set_values3(t_arrays *arr, t_vector *vec);
void	set_values4(t_arrays *arr, t_vector *vec);
int		hit_ax(t_arrays *arr, char **map);

//rays.c
void	make_ray(t_arrays *arr, t_vector *vec, double a);
void	all(t_general *g, char **map);
void	dist_hit(t_arrays *arr, t_wall *w);

//render.c
void	set_textures2(t_texture *t, t_wall *w, t_general *g, t_arrays *arr);
void	set_textures(t_texture *t, t_wall *w, mlx_texture_t *wall, t_arrays *a);
void	walls(t_wall *w, short x, t_general *g, t_arrays *arr);
void	rotate(t_vector *vec, short sign);
void	move(t_general *g, t_vector *vec);

//setup.c
void	setup(t_map	*map, t_general *g);
void	get_player_pos(t_general *g, char **map);
void	get_player_dir(t_general *g, char flag);

//init.c
void	my_keyhook(mlx_key_data_t keydata, void *param);
void	init(t_general *g, t_map *map);
int32_t	ft_color(int32_t r, int32_t g, int32_t b);
void	cel_floor(t_general *g);
void	ft_fr(t_map *map, t_general *g, int flag);
void	ft_free_mat(char **mat);

#endif
