/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouvera <tbouvera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 11:55:22 by tbouvera          #+#    #+#             */
/*   Updated: 2022/10/19 09:48:25 by tbouvera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t		index;
	size_t		new_index;
	size_t		size;
	char		*ptr;

	index = start;
	size = 0;
	new_index = 0;
	if (start >= (unsigned int)ft_strlen(s))
	{
		ptr = ft_calloc (sizeof(char), 1);
		if (!ptr)
			return (NULL);
		return (ptr);
	}
	while (s[index++] != 0 && size != len)
		size++;
	ptr = (char *)malloc (size * sizeof(char) + 1);
	if (!ptr)
		return (NULL);
	index = 0;
	while (index++ < size)
		ptr[new_index++] = s[start++];
	ptr[new_index] = '\0';
	return (ptr);
}
