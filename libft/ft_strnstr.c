/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouvera <tbouvera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 11:55:09 by tbouvera          #+#    #+#             */
/*   Updated: 2022/10/18 10:42:29 by tbouvera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	y;

	i = 0;
	y = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (haystack[i] && i <= len)
	{
		while (haystack[i + y] == needle[y] && needle[y] && (y + i) != len)
		{
			y++;
			if (y == (size_t)ft_strlen(needle))
				return ((char *)haystack + i);
		}
		i ++;
		y = 0;
	}
	return (NULL);
}
