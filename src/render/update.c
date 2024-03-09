/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouvera <tbouvera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 11:52:58 by tbouvera          #+#    #+#             */
/*   Updated: 2024/03/08 15:48:02 by tbouvera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

int	update(t_game *game)
{
	if (game->player.mouse_move == 0)
		mlx_mouse_move(game->mlx_win, 640, 360);
	mlx_clear_window(game->mlx, game->mlx_win);
	if (game->player.side_left == 0)
		side_to_left(game);
	if (game->player.side_right == 0)
		side_to_right(game);
	if (game->player.is_forward == 0)
		forward(game);
	if (game->player.is_backward == 0)
		backward(game);
	if (game->player.is_turn_left == 0)
		turn_left(game);
	if (game->player.is_turn_right == 0)
		turn_right(game);
	raycasting(game, &game->ray);
	return (0);
}

int	key_press(int keycode, t_game *game)
{
	if (keycode == 53)
		kill_game(game);
	if (keycode == 35)
		mlx_mouse_show();
	if (keycode == 35 && game->player.mouse_move == 0)
		delock(game);
	else if (keycode == 35 && game->player.mouse_move == 1)
		lock(game);
	if (keycode == 0)
		game->player.side_left = 0;
	if (keycode == 2)
		game->player.side_right = 0;
	if (keycode == 13)
		game->player.is_forward = 0;
	if (keycode == 1)
		game->player.is_backward = 0;
	if (keycode == 124)
		game->player.is_turn_left = 0;
	if (keycode == 123)
		game->player.is_turn_right = 0;
	return (0);
}

int	key_release(int keycode, t_game *game)
{
	if (keycode == 0)
		game->player.side_left = 1;
	if (keycode == 2)
		game->player.side_right = 1;
	if (keycode == 13)
		game->player.is_forward = 1;
	if (keycode == 1)
		game->player.is_backward = 1;
	if (keycode == 124)
		game->player.is_turn_left = 1;
	if (keycode == 123)
		game->player.is_turn_right = 1;
	return (0);
}

int	mouse_move(int x, int y, t_game *game)
{
	if (x < 635 && game->player.mouse_move == 0)
	{
		game->player.is_turn_right = 0;
		game->player.is_turn_left = 1;
	}
	else if (x > 645 && game->player.mouse_move == 0)
	{
		game->player.is_turn_left = 0;
		game->player.is_turn_right = 1;
	}
	else
	{
		game->player.is_turn_left = 1;
		game->player.is_turn_right = 1;
	}
	return (0);
}

void	hooks(t_game *game)
{
	mlx_hook(game->mlx_win, 17, 0, kill_game, game);
	mlx_hook(game->mlx_win, 2, 1L << 0, key_press, game);
	mlx_hook(game->mlx_win, 3, 1L << 1, key_release, game);
	mlx_hook(game->mlx_win, 6, 0, mouse_move, game);
	mlx_loop_hook(game->mlx, update, game);
	mlx_loop(game->mlx);
}
