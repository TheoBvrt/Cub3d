/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouvera <tbouvera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 11:52:58 by tbouvera          #+#    #+#             */
/*   Updated: 2024/03/08 13:33:21 by tbouvera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	draw_sky_ground(t_game *game, unsigned int buffer[720][1280])
{
	int	y;
	int	x;

	y = game->s_h / 2;
	x = 0;
	while (y < game->s_h)
	{
		x = 0;
		while (x < game->s_w)
			buffer[y][x++] = game->map.ceiling_color;
		y ++;
	}
	y = 0;
	while (y < game->s_h / 2)
	{
		x = 0;
		while (x < game->s_w)
			buffer[y][x++] = game->map.floor_color;
		y ++;
	}
}
