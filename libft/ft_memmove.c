/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouvera <tbouvera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 11:54:01 by tbouvera          #+#    #+#             */
/*   Updated: 2022/10/18 10:42:46 by tbouvera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t		i;
	char		*s;
	char		*d;

	i = 0;
	s = (char *)src;
	d = (char *)dst;
	if (dst != NULL || src != NULL)
	{
		if (d > s)
		{
			while (len-- > 0)
				d[len] = s[len];
		}
		else
		{
			while (i < len)
			{
				d[i] = s[i];
				i++;
			}
		}
		return (dst);
	}
	return (NULL);
}
