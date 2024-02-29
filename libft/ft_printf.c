/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouvera <tbouvera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 11:53:03 by tbouvera          #+#    #+#             */
/*   Updated: 2022/11/01 10:53:22 by tbouvera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_i(va_list args)
{
	int		len;
	char	*str_itoa;

	len = 0;
	str_itoa = ft_itoa(va_arg(args, int));
	len += ft_increment_putstr(str_itoa);
	if (!str_itoa)
		return (0);
	free (str_itoa);
	return (len);
}

static int	ft_u(va_list args)
{
	int		len;
	char	*str_itoa;

	len = 0;
	str_itoa = ft_increment_itoa(va_arg(args, unsigned int));
	if (!str_itoa)
		return (0);
	len += ft_increment_putstr(str_itoa);
	free (str_itoa);
	return (len);
}

static int	ft_check_format(const char *str, int i, va_list args)
{
	int	char_readed;

	char_readed = 0;
	if (str[i] == '%')
		char_readed += ft_increment_percent();
	if (str[i] == 'c')
		char_readed += ft_increment_putchar(va_arg(args, int));
	if (str[i] == 's')
		char_readed += ft_increment_putstr(va_arg(args, char *));
	if (str[i] == 'd' || str[i] == 'i')
		char_readed += ft_i(args);
	if (str[i] == 'u')
		char_readed += ft_u(args);
	if (str[i] == 'x')
		char_readed += ft_dec_to_hex(va_arg(args, int), 1);
	if (str[i] == 'X')
		char_readed += ft_dec_to_hex(va_arg(args, int), 2);
	if (str[i] == 'p')
		char_readed += ft_print_ptr(va_arg(args, unsigned long long));
	return (char_readed);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		char_readed;
	int		i;

	i = 0;
	char_readed = 0;
	va_start (args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			char_readed += ft_check_format(str, i, args);
		}
		else
		{
			ft_putchar_fd(str[i], 1);
			char_readed++;
		}
		i++;
	}
	va_end(args);
	return (char_readed);
}
