/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adhaka <adhaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 14:17:19 by sal-zuba          #+#    #+#             */
/*   Updated: 2024/02/21 17:23:42 by adhaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr2(const char *s, int c)
{
	int	i;

	i = 0;
	while (s && s[i])
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)s + i);
	return (0);
}

char	*ft_strjoin2(char *s1, char *s2)
{
	char		*str;
	size_t		len;
	int			i;
	int			j;

	j = 0;
	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len = ft_strlen2(s1) + ft_strlen2(s2) + 1;
	str = malloc(len);
	if (!str)
		return (NULL);
	while (s1 && s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2 && s2[j])
		str[i++] = s2[j++];
	free(s1);
	str[i] = '\0';
	return (str);
}

int	ft_strlen2(const char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strdup2(char *s)
{
	int		i;
	char	*dup;
	int		j;

	i = 0;
	j = ft_strlen2(s);
	dup = (char *)malloc((j * sizeof(char) + 1));
	if (dup == NULL)
		return (free(dup), NULL);
	while (s[i])
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	*ft_substr2(char const *s, unsigned int start, size_t len)
{
	char	*a;
	size_t	i;
	size_t	j;

	if (start >= (unsigned int)ft_strlen2(s))
		return (NULL);
	i = ft_strlen2(s + start);
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
