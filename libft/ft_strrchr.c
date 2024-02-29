/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouvera <tbouvera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 11:55:13 by tbouvera          #+#    #+#             */
/*   Updated: 2022/10/18 10:42:28 by tbouvera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_strrchr(const char *str, int c)
{
	size_t	index;

	index = ft_strlen(str);
	while (str[index] != ((char)c))
	{
		if (index == 0)
		{
			return (NULL);
		}
		index--;
	}
	return ((unsigned char *)str + index);
}
