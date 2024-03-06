/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouvera <tbouvera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 12:11:48 by tbouvera          #+#    #+#             */
/*   Updated: 2022/10/27 10:19:03 by tbouvera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_check_error(int fd, int buff_size, char **buffer)
{
	if (fd < 0 || buff_size <= 0 || read(fd, 0, 0) < 0)
	{
		if (*buffer != NULL)
			free (*buffer);
		*buffer = NULL;
		return (1);
	}
	return (0);
}

size_t	ft_strlen(const char *str)
{
	size_t	index;

	index = 0;
	while (str[index] != 0)
		index++;
	return (index);
}

char	*ft_strchr(const char *s, int c)
{
	int	index;

	index = 0;
	while (s[index] != ((char)c))
	{
		if (s[index] == '\0')
		{
			return (NULL);
		}
		index++;
	}
	return ((char *)s + index);
}

char	*ft_strdup(const char *s1)
{
	char	*dest;
	size_t	str_size;
	int		index;

	str_size = ft_strlen(s1);
	dest = (char *)malloc (sizeof (char) * str_size + 1);
	if (!dest)
		return (NULL);
	index = 0;
	while (s1[index] != '\0')
	{
		dest[index] = s1[index];
		index++;
	}
	dest[index] = '\0';
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	size_t	total_size;
	int		index;
	int		ptr_index;

	index = 0;
	ptr_index = 0;
	total_size = ft_strlen(s1) + ft_strlen(s2);
	ptr = (char *)malloc (total_size * sizeof(char) + 1);
	if (!ptr)
		return (NULL);
	while (s1[index] != 0)
	{
		ptr[index] = s1[index];
		index ++;
	}
	ptr_index = index;
	index = 0;
	while (s2[index] != 0)
		ptr[ptr_index++] = s2[index++];
	ptr[ptr_index] = '\0';
	return (ptr);
}
