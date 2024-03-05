/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouvera <tbouvera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 11:52:58 by tbouvera          #+#    #+#             */
/*   Updated: 2022/10/18 10:43:07 by tbouvera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../cub3d.h"

void	image_loader(t_game *game)
{
	game->image.texture = mlx_xpm_file_to_image(game->mlx,
			"./images/north.xpm", &game->image.pw, &game->image.ph);
	game->image.stone = mlx_xpm_file_to_image(game->mlx,
			"./images/stone.xpm", &game->image.pw, &game->image.ph);
	game->image.coloredstone = mlx_xpm_file_to_image(game->mlx,
			"./images/coloredstone.xpm", &game->image.pw, &game->image.ph);
	game->image.brick = mlx_xpm_file_to_image(game->mlx,
			"./images/brick.xpm", &game->image.pw, &game->image.ph);
}

void	image_init_image(t_game *game)
{
	game->data.img = mlx_new_image(game->mlx, game->s_w, game->s_h);
	game->game_img.img = mlx_new_image(game->mlx, game->s_w, game->s_h);
	game->game_img.addr = mlx_get_data_addr(game->game_img.img,
			&game->game_img.bits_per_pixel,
			&game->game_img.line_length, &game->game_img.endian);
	game->data.addr = mlx_get_data_addr(game->data.img,
			&game->data.bits_per_pixel,
			&game->data.line_length, &game->data.endian);
}
