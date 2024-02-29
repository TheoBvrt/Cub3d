/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouvera <tbouvera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 11:54:43 by tbouvera          #+#    #+#             */
/*   Updated: 2022/10/18 10:42:36 by tbouvera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	size_t	total_size;
	int		index;
	int		ptr_index;

	index = 0;
	ptr_index = 0;
	total_size = ft_strlen(s1) + ft_strlen(s2);
	ptr = (char *)malloc (total_size * sizeof(char) + 1);
	if (!ptr)
		return (NULL);
	while (s1[index] != 0)
	{
		ptr[index] = s1[index];
		index ++;
	}
	ptr_index = index;
	index = 0;
	while (s2[index] != 0)
		ptr[ptr_index++] = s2[index++];
	ptr[ptr_index] = 0;
	return (ptr);
}
