/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouvera <tbouvera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 11:52:58 by tbouvera          #+#    #+#             */
/*   Updated: 2022/10/18 10:43:07 by tbouvera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../cub3d.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	draw_sky_ground(t_game *game, unsigned int buffer[720][1280])
{
	for (int y = game->s_h / 2; y < game->s_h; y++) {
		for (int x = 0; x < game->s_w; x++) {
			buffer[y][x] = green;
		}
	}

	for (int y = 0; y < game->s_h / 2; y++) {
		for (int x = 0; x < game->s_w; x++) {
			buffer[y][x] = blue;
		}
	}
}