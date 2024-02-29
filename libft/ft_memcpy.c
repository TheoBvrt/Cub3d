/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouvera <tbouvera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 12:05:54 by tbouvera          #+#    #+#             */
/*   Updated: 2022/10/18 10:42:47 by tbouvera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	index;

	index = 0;
	if (!dest && !src)
		return (NULL);
	while (index < n)
	{
		((unsigned char *)dest)[index] = ((unsigned char *)src)[index];
		index++;
	}
	return ((unsigned char *)dest);
}
