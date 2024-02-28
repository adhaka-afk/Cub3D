/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_colors2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adhaka <adhaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 20:31:22 by adhaka            #+#    #+#             */
/*   Updated: 2024/02/28 20:31:35 by adhaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	check_num_c(char *c)
{
	int	j;
	int	i;

	i = -1;
	j = 0;
	while (c[++i])
	{
		if (c[i] == ',')
		{
			if (not_num(c, j, i))
				return (-1);
			j = i + 1;
		}
	}
	return (0);
}

int	check_num_f(char *f)
{
	int	i;
	int	j;

	j = 0;
	i = -1;
	while (f[++i])
	{
		if (f[i] == ',')
		{
			if (not_num(f, j, i))
				return (-1);
			j = i + 1;
		}
	}
	return (0);
}

int	not_num(char *str, int start, int end)
{
	while (start < end)
	{
		if (str[start] < '0' || str[start] > '9')
			return (-1);
		start++;
	}
	return (0);
}
