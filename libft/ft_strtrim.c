/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouvera <tbouvera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 11:55:17 by tbouvera          #+#    #+#             */
/*   Updated: 2022/10/18 10:42:23 by tbouvera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_checker(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i] != 0)
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

static int	ft_get_index(char const *str, char const *set)
{
	int	index;

	index = 0;
	while (ft_checker(str[index], set) == 1)
		index++;
	return (index);
}

static int	ft_get_ptr_size(int index, int last_index)
{
	int	value;

	value = 0;
	while (index++ <= last_index)
		value++;
	return (value);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int			index;
	int			last_index;
	size_t		ptr_size;
	char		*ptr;

	index = ft_get_index(s1, set);
	ptr_size = 0;
	ptr = NULL;
	last_index = (int)ft_strlen(s1) - 1;
	if (ft_strlen(s1) == 0)
		return (ft_calloc(sizeof(char), 1));
	while (ft_checker(s1[last_index], set) == 1)
		last_index--;
	ptr_size = ft_get_ptr_size(index, last_index);
	ptr = (char *)malloc (sizeof(char) * ptr_size + 1);
	if (!ptr)
		return (NULL);
	ptr_size = 0;
	index = ft_get_index(s1, set);
	while (index <= last_index)
		ptr[ptr_size++] = s1[index++];
	ptr[ptr_size] = 0;
	return (ptr);
}
