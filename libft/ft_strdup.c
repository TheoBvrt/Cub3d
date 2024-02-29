/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouvera <tbouvera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 11:54:35 by tbouvera          #+#    #+#             */
/*   Updated: 2022/10/18 10:42:37 by tbouvera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dest;
	size_t	str_size;
	int		index;

	str_size = ft_strlen(s1);
	dest = (char *)malloc (sizeof (char) * str_size + 1);
	if (!dest)
		return (NULL);
	index = 0;
	while (s1[index] != '\0')
	{
		dest[index] = s1[index];
		index++;
	}
	dest[index] = '\0';
	return (dest);
}
