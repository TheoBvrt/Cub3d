/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorcom- <jmorcom-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 03:32:14 by jmorcom-          #+#    #+#             */
/*   Updated: 2023/07/28 16:48:37 by jmorcom-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

static int	read_line(int fd, char **cache, int count)
{
	char	buf[BUFFER_SIZE + 1];
	char	*old_cache;

	count = -2;
	while (count)
	{
		count = read(fd, buf, BUFFER_SIZE);
		if (count == -1 || count == 0)
			return (count);
		buf[count] = '\0';
		if (*cache == NULL)
			*cache = ft_strdup(buf);
		else
		{
			old_cache = *cache;
			*cache = ft_strjoin(*cache, buf);
			free(old_cache);
		}
		if (ft_strchr(*cache, '\n'))
			break ;
	}
	return (count);
}

static int	get_line(char **res, char **cache, int fd, int *fd_status)
{
	if (!(*cache == NULL || !ft_strchr(*cache, '\n')))
		return (0);
	*res = NULL;
	*fd_status = read_line(fd, &(*cache), 0);
	if (*fd_status == 0)
	{
		if (*cache == NULL)
			return (1);
		*res = ft_strdup(*cache);
		free(*cache);
		*cache = NULL;
		return (2);
	}
	else if (*fd_status == -1)
	{
		free(*cache);
		*cache = NULL;
		return (1);
	}
	return (0);
}

char	*get_next_line(int fd)
{
	static char	*cache = NULL;
	char		*res;
	char		*end;
	char		*old_cache;
	int			fd_status;

	if (get_line(&res, &cache, fd, &fd_status))
		return (res);
	if (ft_strchr(cache, '\n'))
	{
		res = ft_strdup(cache);
		end = ft_strchr(res, '\n') + 1;
		*end = '\0';
		old_cache = cache;
		cache = ft_strdup((ft_strchr(cache, '\n') + 1));
		free(old_cache);
		if (ft_strlen(cache) == 0)
		{
			free(cache);
			cache = NULL;
		}
		return (res);
	}
	return (NULL);
}
