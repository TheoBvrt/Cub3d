/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dec_to_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouvera <tbouvera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 11:53:03 by tbouvera          #+#    #+#             */
/*   Updated: 2022/11/01 10:53:20 by tbouvera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_convert(unsigned int n, int mod)
{
	if (n >= 16)
	{
		ft_convert(n / 16, mod);
		ft_convert(n % 16, mod);
	}
	else
	{
		if (n <= 9)
			ft_putchar_fd(n + '0', 1);
		else
		{
			if (mod == 1)
				ft_putchar_fd((n - 10 + 'a'), 1);
			if (mod == 2)
				ft_putchar_fd((n - 10 + 'A'), 1);
		}
	}
}

int	ft_dec_to_hex(unsigned int n, int mod)
{
	unsigned int	i;
	int				t;

	i = n;
	t = 0;
	if (n == 0)
		return (write(1, "0", 1));
	else
		ft_convert(n, mod);
	while (i != 0)
	{
		i /= 16;
		t ++;
	}
	return (t);
}
