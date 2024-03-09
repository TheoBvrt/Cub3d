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

void	side_to_right(t_game *g)
{
	if (g->map.tiles[(int)
			(g->player.pos_x + g->player.dir_y * (g->player.move_speed + 0.4))]
		[(int)(g->player.pos_y)] == '0')
	{
		g->player.pos_x += g->player.dir_y * g->player.move_speed;
	}
	if (g->map.tiles[(int)(g->player.pos_x)]
			[(int)(g->player.pos_y - g->player.dir_x
		* (g->player.move_speed + 0.4))] == '0')
	{
		g->player.pos_y -= g->player.dir_x * g->player.move_speed;
	}
}

void	side_to_left(t_game *g)
{
	if (g->map.tiles[(int)
			(g->player.pos_x + g->player.dir_y * (g->player.move_speed - 0.4))]
		[(int)(g->player.pos_y)] == '0')
	{
		g->player.pos_x -= g->player.dir_y * g->player.move_speed;
	}
	if (g->map.tiles[(int)(g->player.pos_x)]
			[(int)(g->player.pos_y - g->player.dir_x
		* (g->player.move_speed - 0.4))] == '0')
	{
		g->player.pos_y += g->player.dir_x * g->player.move_speed;
	}
}
