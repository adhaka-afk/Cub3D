/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adhaka <adhaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 18:55:38 by sal-zuba          #+#    #+#             */
/*   Updated: 2024/02/21 17:30:08 by adhaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_len(char *s)
{
	int	i;

	i = 0;
	while (s && s[i] && s[i] != '\n')
	{
		i++;
	}
	return (i);
}

void	*ft_calloc2(size_t nmemb, size_t size)
{
	void			*s;
	unsigned char	*a;
	size_t			i;

	i = 0;
	if (size && SIZE_MAX / size < nmemb)
		return (NULL);
	s = malloc(size * nmemb);
	if (s == NULL)
		return (NULL);
	a = (unsigned char *)s;
	while (i < (size * nmemb))
	{
		a[i] = '\0';
		i++;
	}
	return (a);
}

void	ft_free1(char **str, char **buffer)
{
	free(*str);
	*str = NULL;
	free(*buffer);
	*buffer = NULL;
}

char	*ft_read(int fd, char *s)
{
	char	*str;
	int		bytes;

	bytes = 1;
	str = malloc(BUFFER_SIZE + 1);
	if (str == NULL)
		return (NULL);
	while (bytes > 0)
	{
		bytes = read(fd, str, BUFFER_SIZE);
		if (bytes == -1)
			return (free(str), free(s), NULL);
		str[bytes] = 0;
		s = ft_strjoin2(s, str);
		if (ft_strchr2(s, '\n'))
			break ;
	}
	free(str);
	return (s);
}

char	*get_next_line(int fd)
{
	static char			*s;
	char				*tmp;
	char				*line;

	if (s == NULL)
		s = ft_calloc2(1, 1);
	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		free(s);
		s = NULL;
		return (NULL);
	}
	s = ft_read(fd, s);
	line = ft_substr2(s, 0, ft_len(s) + 1);
	if (line == NULL)
		return (ft_free1(&s, &line), NULL);
	tmp = s;
	s = ft_substr2(tmp, ft_len(tmp) + 1, ft_strlen2(tmp));
	free(tmp);
	return (line);
}
