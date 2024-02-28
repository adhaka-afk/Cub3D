/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adhaka <adhaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 19:33:25 by sal-zuba          #+#    #+#             */
/*   Updated: 2024/02/21 17:36:05 by adhaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*a;
	size_t	i;
	size_t	j;

	if (start >= (unsigned int)ft_strlen(s))
		return (ft_strdup(""));
	i = ft_strlen(s + start);
	if (i > len)
		i = len;
	a = (char *)malloc(i + 1);
	if (!a)
		return (NULL);
	j = 0;
	while (j < i)
	{
		a[j] = s[start + j];
		j++;
	}
	a[j] = '\0';
	return (a);
}
