/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorcom- <jmorcom-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 23:16:06 by jmorcom-          #+#    #+#             */
/*   Updated: 2023/07/28 17:34:36 by jmorcom-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strchr_gnl(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == '\0')
			return (i);
		i++;
	}
	return (0);
}

int	ft_strlen_gnl(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

int	ft_size(const char *s)
{
	int	size;

	size = 0;
	if (!s)
		return (0);
	while (s[size] != '\n' && s[size])
		size++;
	return (size);
}

char	*ft_join(char	*buff, char	*remain_str, ssize_t rd_char)
{
	int		i;
	int		j;
	char	*tmp;

	j = 0;
	i = -1;
	if (!remain_str)
	{
		remain_str = malloc(1);
		if (!remain_str)
			return (NULL);
		remain_str[0] = 0;
	}
	tmp = malloc(ft_strlen_gnl(remain_str) + rd_char + 1);
	if (!tmp)
		return (NULL);
	while (remain_str[++i])
		tmp[i] = remain_str[i];
	if (remain_str)
		free(remain_str);
	while (j < rd_char)
		tmp[i++] = buff[j++];
	tmp[i] = 0;
	return (tmp);
}
