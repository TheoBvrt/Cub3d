/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouvera <tbouvera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 12:11:48 by tbouvera          #+#    #+#             */
/*   Updated: 2022/10/27 10:20:54 by tbouvera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_get_first_line(char *buffer)
{
	char	*ptr;
	int		i;

	i = 0;
	if (buffer[i] == '\0')
		return (NULL);
	while (buffer[i] != '\0' && buffer[i] != '\n')
		i++;
	ptr = malloc (sizeof(char) * (i) + 2);
	if (!ptr)
		return (NULL);
	i = 0;
	while (buffer[i] != '\0' && buffer[i] != '\n')
	{
		ptr[i] = buffer[i];
		i ++;
	}
	if (buffer[i] == '\n')
	{
		ptr[i] = '\n';
		i ++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*save_read(int fd, char *buffer, int read_bytes)
{
	char	*buff;
	char	*tmp;

	buff = (char *)malloc((1 + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	buff[0] = '\0';
	while (read_bytes != 0 && !ft_strchr(buff, '\n'))
	{
		if (read_bytes <= 0)
		{
			free(buff);
			if (read_bytes == 0)
				return (buffer);
			return (NULL);
		}
		read_bytes = read(fd, buff, 1);
		buff[read_bytes] = '\0';
		tmp = buffer;
		buffer = ft_strjoin(tmp, buff);
		free(tmp);
	}
	free(buff);
	return (buffer);
}

char	*ft_save(char *buffer)
{
	char	*ptr;
	int		i;
	int		s;
	int		t;

	i = 0;
	s = 0;
	t = 0;
	while (buffer[i] != '\n')
	{
		if (buffer[i++] == '\0')
			return (NULL);
	}
	i ++;
	t = i;
	while (buffer[i++] != '\0')
		s ++;
	ptr = (char *)malloc (sizeof(char) * (s + 1));
	if (!ptr)
		return (NULL);
	s = 0;
	while (buffer[t] != '\0')
		ptr[s++] = buffer[t++];
	ptr[s] = '\0';
	return (ptr);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;
	char		*tmp;
	int			read_bytes;

	read_bytes = 1;
	if (ft_check_error(fd, 1, &buffer) == 1)
		return (NULL);
	if (buffer == NULL)
	{
		buffer = malloc (sizeof(char) * 1);
		if (!buffer)
			return (NULL);
		buffer[0] = '\0';
	}
	buffer = save_read(fd, buffer, read_bytes);
	if (buffer == NULL)
		return (NULL);
	tmp = ft_strdup(buffer);
	line = ft_get_first_line(buffer);
	free (buffer);
	buffer = ft_save(tmp);
	free (tmp);
	return (line);
}
