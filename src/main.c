/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouvera <tbouvera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 11:58:52 by jmorcom-          #+#    #+#             */
/*   Updated: 2024/03/08 15:47:08 by tbouvera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"
#include "stdio.h"

void	my_exit(char *string, t_carte *carte)
{
	free(carte);
	ft_putstr_fd("Error\n", STDERR_FILENO);
	ft_putstr_fd(string, STDERR_FILENO);
	exit (1);
}

int	cube3d_init(t_game *game)
{
	game->s_w = 1280;
	game->s_h = 720;
	game->exit = 0;
	game->player.dir_x = -1;
	game->player.dir_y = 0;
	game->player.plane_x = 0;
	game->player.plane_y = 0.66;
	game->player.is_forward = 1;
	game->player.is_backward = 1;
	game->player.is_turn_left = 1;
	game->player.is_turn_right = 1;
	game->player.side_left = 1;
	game->player.side_right = 1;
	game->player.move_speed = 0.04;
	game->player.mouse_move = 0;
	return (0);
}

void	print_tab(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	printf("%d", game->map.size.y);
	while (y < game->map.size.y)
	{
		printf("\n");
		while (x < game->map.size.x)
		{
			printf("%c", game->map.tiles[y][x]);
			x ++;
		}
		x = 0;
		y ++;
	}
}

int	main(int argc, char *argv[])
{
	t_game			game;
	t_raycasting	ray;
	t_carte			*carte;

	carte = ft_calloc(1, sizeof (t_carte));
	if (cube3d_init(&game) == 1)
		return (1);
	check_args(argc, argv, carte);
	if (parse(argv[1], carte, &game) == ERROR)
	{
		free(carte);
		return (1);
	}
	game.map = carte->map;
	game.player.pos_x = game.map.ply_pos.x + 0.5;
	game.player.pos_y = game.map.ply_pos.y + 0.5;
	game.mlx = mlx_init();
	game.mlx_win = mlx_new_window(game.mlx, game.s_w, game.s_h, "cub3d");
	mlx_mouse_hide();
	image_loader(&game);
	image_init_image(&game);
	rotation_to(&game, game.map.ply_dir);
	hooks(&game);
	return (0);
}
