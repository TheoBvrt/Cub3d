/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_update.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouvera <tbouvera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 11:52:58 by tbouvera          #+#    #+#             */
/*   Updated: 2024/03/08 14:36:58 by tbouvera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

void	ray_calculator(t_game *game, t_raycasting *ray)
{
	if (ray->side == 0)
		ray->perp_wall_dist = (ray->side_dist_x - ray->delta_dist_x);
	else
		ray->perp_wall_dist = (ray->side_dist_y - ray->delta_dist_y);
	ray->line_height = (int)(game->s_h / ray->perp_wall_dist);
	ray->draw_start = -ray->line_height / 2 + game->s_h / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + game->s_h / 2;
	if (ray->draw_end >= game->s_h)
		ray->draw_end = game->s_h - 1;
	if (ray->side == 0)
		ray->wall_x = game->player.pos_y + ray->perp_wall_dist * ray->ray_dir_y;
	else
		ray->wall_x = game->player.pos_x
			+ ray->perp_wall_dist * ray->ray_dir_x ;
	ray->wall_x -= floor((ray->wall_x));
	ray->tex_x = (int)(ray->wall_x * (double)64);
	if (ray->side == 0 && ray->ray_dir_x > 0)
		ray->tex_x = 64 - ray->tex_x - 1;
	ray->step = 1.0 * 64 / ray->line_height;
	ray->text_pos = (ray->draw_start - game->s_h / 2 + ray->line_height / 2)
		* ray->step;
}

void	texture_selector(t_game *game, t_raycasting *ray)
{
	if (game->map.tiles[ray->map_x][ray->map_y] == '1')
	{
		if (ray->side == 0)
		{
			if (ray->ray_dir_x > 0)
				ray->tex_data = mlx_get_data_addr
					(game->image.north, &ray->bpp, &ray->sl, &ray->end);
			else
				ray->tex_data = mlx_get_data_addr
					(game->image.south, &ray->bpp, &ray->sl, &ray->end);
		}
		else
		{
			if (ray->ray_dir_y > 0)
				ray->tex_data = mlx_get_data_addr
					(game->image.east, &ray->bpp, &ray->sl, &ray->end);
			else
				ray->tex_data = mlx_get_data_addr
					(game->image.west, &ray->bpp, &ray->sl, &ray->end);
		}
	}
}

void	set_ray_dir(t_game *game, t_raycasting *ray)
{
	if (ray->ray_dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (game->player.pos_x - ray->map_x)
			* ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->map_x + 1.0 - game->player.pos_x)
			* ray->delta_dist_x;
	}
	if (ray->ray_dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (game->player.pos_y - ray->map_y)
			* ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (ray->map_y + 1.0 - game->player.pos_y)
			* ray->delta_dist_y;
	}
}

void	init_ray(t_game *game, t_raycasting *ray)
{
	while (ray->hit == 0)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			ray->map_x += ray->step_x ;
			ray->side = 0;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (game->map.tiles[ray->map_x][ray->map_y] == '1')
			ray->hit = 1;
	}
}

void	raycasting(t_game *game, t_raycasting *ray)
{
	unsigned int	buffer[720][1280];

	ray->x = 0;
	draw_sky_ground(game, buffer);
	while (ray->x < game->s_w)
	{
		set_values(game, ray);
		set_ray_dir(game, ray);
		init_ray(game, ray);
		ray_calculator(game, ray);
		texture_selector(game, ray);
		buffer_fill(game, ray, buffer);
		ray->x++;
	}
	set_buffer(game, buffer);
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->game_img.img, 0, 0);
}
