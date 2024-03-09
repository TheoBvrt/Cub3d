/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorcom- <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 11:59:56 by jmorcom-          #+#    #+#             */
/*   Updated: 2024/03/06 11:59:57 by jmorcom-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	error_print(char *str)
{
	write(STDERR_FILENO, str, ft_strlen(str));
}

t_point_d	new_point_d(double x, double y)
{
	t_point_d	new;

	new.x = x;
	new.y = y;
	return (new);
}

double	vec2_to_angle(t_point_d v)
{
	return (atan2(v.y, v.x));
}
