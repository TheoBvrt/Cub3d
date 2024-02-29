/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_itoa.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouvera <tbouvera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 11:53:03 by tbouvera          #+#    #+#             */
/*   Updated: 2022/11/01 10:53:23 by tbouvera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_tab_fill_min_int(char *ptr)
{
	ptr[0] = '4';
	ptr[1] = '2';
	ptr[2] = '9';
	ptr[3] = '4';
	ptr[4] = '9';
	ptr[5] = '6';
	ptr[6] = '7';
	ptr[7] = '2';
	ptr[8] = '9';
	ptr[9] = '5';
}

static int	ft_get_size(unsigned int nb)
{
	int	size;

	size = 0;
	while (nb >= 10)
	{
		nb = nb / 10;
		size ++;
	}
	if (nb < 10)
		size++;
	return (size);
}

static void	ft_tab_fill(char *ptr, unsigned int nb, int max_index)
{
	int	index;

	index = max_index - 1;
	while (nb >= 10)
	{
		ptr[index] = ((nb % 10) + '0');
		nb = nb / 10;
		index --;
	}
	if (nb < 10)
		ptr[index] = (nb + '0');
}

char	*ft_increment_itoa(unsigned int n)
{
	int		size;
	char	*ptr;

	if (n != 4294967295)
		size = ft_get_size(n);
	else
		size = 10;
	ptr = ft_calloc(sizeof(char), size + 1);
	if (!ptr)
		return (NULL);
	if (n != 4294967295)
		ft_tab_fill(ptr, n, size);
	else
		ft_tab_fill_min_int(ptr);
	return (ptr);
}
