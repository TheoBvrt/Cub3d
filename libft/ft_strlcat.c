/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouvera <tbouvera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 11:54:47 by tbouvera          #+#    #+#             */
/*   Updated: 2022/10/18 10:42:35 by tbouvera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t dstsize)
{
	size_t	index1;
	size_t	return_value;
	size_t	index2;

	index1 = ft_strlen(dest);
	index2 = 0;
	return_value = index1 + ft_strlen(src);
	if (ft_strlen(dest) >= dstsize)
		return (dstsize + ft_strlen(src));
	while (index1 < (dstsize - 1) && src[index2])
	{
		dest[index1] = src[index2];
		index1++;
		index2++;
	}
	dest[index1] = '\0';
	return (return_value);
}
