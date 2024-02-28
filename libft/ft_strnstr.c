/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sal-zuba <sal-zuba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 17:56:13 by sal-zuba          #+#    #+#             */
/*   Updated: 2023/04/12 15:51:34 by sal-zuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s, const char *b, size_t len)
{
	size_t	i;
	size_t	j;

	j = 0;
	i = ft_strlen(b);
	if (i == 0)
		return ((char *)s);
	while (j < len && s[j])
	{
		if (j + i <= len && !ft_strncmp(s + j, b, i))
			return ((char *)s + j);
		else
			j++;
	}
	return (0);
}
