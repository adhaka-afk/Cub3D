/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adhaka <adhaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 22:00:55 by adhaka            #+#    #+#             */
/*   Updated: 2024/02/28 20:47:42 by adhaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_error(char *str)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	ft_putstr_fd(str, STDERR_FILENO);
	exit(EXIT_FAILURE);
}

int	is_vext(char *f_name, char *str)
{
	size_t	len;

	len = ft_strlen(f_name);
	if (len >= 4 && ft_strncmp(f_name + len - 4, str, 4) == 0)
		return (0);
	else
		return (1);
}

int	r_eadable(char *f_name)
{
	int		fd;
	char	*tmp;
	char	*tmp2;

	tmp = ft_strdup("maps/");
	tmp2 = ft_strjoin(tmp, f_name);
	free(tmp);
	fd = open(tmp2, O_RDONLY);
	if (fd == -1)
		return (free(tmp2), 1);
	close(fd);
	free(tmp2);
	return (0);
}

void	ft_free_mat(char **mat)
{
	int	i;

	i = -1;
	while (mat[++i])
		free(mat[i]);
	free(mat);
	mat = NULL;
}
