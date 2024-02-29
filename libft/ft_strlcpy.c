/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouvera <tbouvera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 11:54:51 by tbouvera          #+#    #+#             */
/*   Updated: 2022/10/18 10:42:33 by tbouvera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t destsize)
{
	size_t	index;
	size_t	src_size;

	index = 0;
	src_size = 0;
	if (destsize != 0)
	{
		while (src[index] != '\0' && index != (destsize - 1))
		{
			dest[index] = src[index];
			index++;
		}
		dest[index] = '\0';
	}
	while (src[src_size] != '\0')
		src_size++;
	return (src_size);
}
