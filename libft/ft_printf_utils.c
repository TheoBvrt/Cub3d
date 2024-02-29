/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouvera <tbouvera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 11:53:03 by tbouvera          #+#    #+#             */
/*   Updated: 2022/11/01 10:53:21 by tbouvera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_increment_putchar(int c)
{
	write (1, &c, 1);
	return (1);
}

int	ft_increment_putstr(char *s)
{
	int	index;
	int	return_value;

	index = 0;
	return_value = 0;
	if (s == NULL)
	{
		write (1, "(null)", 6);
		return (6);
	}
	while (s[index] != '\0')
	{
		write (1, s + index, 1);
		index ++;
		return_value++;
	}
	return (return_value);
}

int	ft_increment_percent(void)
{
	write (1, "%", 1);
	return (1);
}
