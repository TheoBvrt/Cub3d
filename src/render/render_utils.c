/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouvera <tbouvera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 11:52:58 by tbouvera          #+#    #+#             */
/*   Updated: 2024/03/08 14:59:06 by tbouvera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

void	set_buffer(t_game *game, unsigned int buffer[720][1280])
{
	int	y;
	int	x;
	int	pos;

	y = 0;
	while (y < game->s_h)
	{
		x = 0;
		while (x < game->s_w)
		{
			pos = (y * game->game_img.line_length)
				+ (x * (game->game_img.bits_per_pixel / 8));
			*(unsigned int *)(game->game_img.addr + pos) = buffer[y][x];
			x ++;
		}
		y ++;
	}
}

void	buffer_fill(t_game *game, t_raycasting *ray, unsigned int b[720][1280])
{
	int	y;
	int	tex_y;

	(void)game;
	y = ray->draw_start;
	while (y <= ray->draw_end)
	{
		tex_y = (int)ray->text_pos & (64 - 1);
		ray->text_pos += ray->step;
		ray->color = *(int *)(ray->tex_data
				+ (tex_y * ray->sl + ray->tex_x * (ray->bpp / 8)));
		b[y][ray->x] = ray->color;
		y ++;
	}
}

void	set_values(t_game *game, t_raycasting *ray)
{
	ray->hit = 0;
	ray->camera_x = 2 * ray->x / (double)game->s_w - 1;
	ray->ray_dir_x = game->player.dir_x + game->player.plane_x * ray->camera_x;
	ray->ray_dir_y = game->player.dir_y + game->player.plane_y * ray->camera_x;
	ray->map_x = (int)game->player.pos_x;
	ray->map_y = (int)game->player.pos_y;
	if (ray->ray_dir_x == 0)
		ray->delta_dist_x = 1e30;
	else
		ray->delta_dist_x = fabs(1 / ray->ray_dir_x);
	if (ray->ray_dir_x == 0)
		ray->delta_dist_y = 1e30;
	else
		ray->delta_dist_y = fabs(1 / ray->ray_dir_y);
}
