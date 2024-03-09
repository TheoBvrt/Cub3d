/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouvera <tbouvera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 11:52:58 by tbouvera          #+#    #+#             */
/*   Updated: 2024/03/08 13:13:30 by tbouvera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

void	forward(t_game *g)
{
	if (g->map.tiles[(int)
			(g->player.pos_x + g->player.dir_x * (g->player.move_speed + 0.4))]
		[(int)(g->player.pos_y)] == '0')
	{
		g->player.pos_x += g->player.dir_x * g->player.move_speed;
	}
	if (g->map.tiles[(int)
			(g->player.pos_x)][(int)(g->player.pos_y
		+ g->player.dir_y * (g->player.move_speed + 0.4))] == '0')
	{
		g->player.pos_y += g->player.dir_y * g->player.move_speed;
	}
}

void	backward(t_game *g)
{
	if (g->map.tiles[(int)
			(g->player.pos_x - g->player.dir_x * (g->player.move_speed + 0.4))]
		[(int)(g->player.pos_y)] == '0')
	{
		g->player.pos_x -= g->player.dir_x * g->player.move_speed;
	}
	if (g->map.tiles[(int)
			(g->player.pos_x)][(int)(g->player.pos_y
		- g->player.dir_y * (g->player.move_speed + 0.4))] == '0')
	{
		g->player.pos_y -= g->player.dir_y * g->player.move_speed;
	}
}

void	turn_left(t_game *game)
{
	double	old_dir_x;
	double	old_plane_y;

	old_dir_x = game->player.dir_x;
	game->player.dir_x = game->player.dir_x * cos(-game->player.move_speed)
		- game->player.dir_y * sin(-game->player.move_speed);
	game->player.dir_y = old_dir_x * sin(-game->player.move_speed)
		+ game->player.dir_y * cos(-game->player.move_speed);
	old_plane_y = game->player.plane_x;
	game->player.plane_x = game->player.plane_x * cos(-game->player.move_speed)
		- game->player.plane_y * sin(-game->player.move_speed);
	game->player.plane_y = old_plane_y * sin(-game->player.move_speed)
		+ game->player.plane_y * cos(-game->player.move_speed);
}

void	turn_right(t_game *game)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = game->player.dir_x;
	game->player.dir_x = game->player.dir_x * cos(game->player.move_speed)
		- game->player.dir_y * sin(game->player.move_speed);
	game->player.dir_y = old_dir_x * sin(game->player.move_speed)
		+ game->player.dir_y * cos(game->player.move_speed);
	old_plane_x = game->player.plane_x;
	game->player.plane_x = game->player.plane_x * cos(game->player.move_speed)
		- game->player.plane_y * sin(game->player.move_speed);
	game->player.plane_y = old_plane_x * sin(game->player.move_speed)
		+ game->player.plane_y * cos(game->player.move_speed);
}

void	rotation_to(t_game *game, int orientation)
{
	double	rotation_angle;
	double	old_dir_x;
	double	old_plane_x;

	if (orientation == EAST)
		rotation_angle = -M_PI / 2;
	if (orientation == WEST)
		rotation_angle = M_PI / 2;
	if (orientation == SOUTH)
		rotation_angle = M_PI;
	if (orientation == NORTH)
		return ;
	old_dir_x = game->player.dir_x;
	game->player.dir_x = game->player.dir_x * cos(rotation_angle)
		- game->player.dir_y * sin(rotation_angle);
	game->player.dir_y = old_dir_x * sin(rotation_angle)
		+ game->player.dir_y * cos(rotation_angle);
	old_plane_x = game->player.plane_x;
	game->player.plane_x = game->player.plane_x * cos(rotation_angle)
		- game->player.plane_y * sin(rotation_angle);
	game->player.plane_y = old_plane_x * sin(rotation_angle)
		+ game->player.plane_y * cos(rotation_angle);
}
