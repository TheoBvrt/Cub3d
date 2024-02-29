/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouvera <tbouvera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 11:53:48 by tbouvera          #+#    #+#             */
/*   Updated: 2022/10/18 10:42:50 by tbouvera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	index;

	index = 0;
	if (!n)
		return (NULL);
	while (index < n)
	{
		if (((unsigned char *)s)[index] == (unsigned char)c)
			return ((char *)s + index);
		index++;
	}
	return (NULL);
}
