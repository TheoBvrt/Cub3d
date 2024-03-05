/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_buffer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouvera <tbouvera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 11:52:58 by tbouvera          #+#    #+#             */
/*   Updated: 2022/10/18 10:43:07 by tbouvera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../cub3d.h"

void	set_buffer(t_game *game, unsigned int buffer[720][1280])
{
	for (int y = 0; y < game->s_h; y++) {
		for (int x = 0; x < game->s_w; x++) {
			int pos = (y * game->game_img.line_length) + (x * (game->game_img.bits_per_pixel / 8));
				*(unsigned int*)(game->game_img.addr + pos) = buffer[y][x];
		}
	}
}

void	buffer_feel(t_game *gane, t_raycasting *ray, unsigned int b[720][1280])
{
	for (int y = ray->draw_start; y < ray->draw_end; y++)
	{
		int texY = (int)ray->text_pos & (64 - 1);
		ray->text_pos += ray->step;
		ray->color = *(int*)(ray->tex_data + (texY * ray->sl + ray->tex_x * (ray->bpp / 8)));
		b[y][ray->x] = ray->color;
	}
}