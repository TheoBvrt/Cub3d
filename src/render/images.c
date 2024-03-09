/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouvera <tbouvera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 11:52:58 by tbouvera          #+#    #+#             */
/*   Updated: 2024/03/08 15:47:26 by tbouvera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

void	image_loader(t_game *game)
{
	game->image.north = mlx_xpm_file_to_image(game->mlx,
			game->tex_path.no_path, &game->image.pw, &game->image.ph);
	game->image.south = mlx_xpm_file_to_image(game->mlx,
			game->tex_path.so_path, &game->image.pw, &game->image.ph);
	game->image.east = mlx_xpm_file_to_image(game->mlx,
			game->tex_path.ea_path, &game->image.pw, &game->image.ph);
	game->image.west = mlx_xpm_file_to_image(game->mlx,
			game->tex_path.we_path, &game->image.pw, &game->image.ph);
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

void	destroy_images(t_game *game)
{
	mlx_destroy_image(game->mlx, game->data.img);
	mlx_destroy_image(game->mlx, game->game_img.img);
	mlx_destroy_image(game->mlx, game->image.north);
	mlx_destroy_image(game->mlx, game->image.south);
	mlx_destroy_image(game->mlx, game->image.west);
	mlx_destroy_image(game->mlx, game->image.east);
}
