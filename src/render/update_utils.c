/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouvera <tbouvera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 11:59:56 by jmorcom-          #+#    #+#             */
/*   Updated: 2024/03/08 13:02:34 by tbouvera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

int	kill_game(t_game *game)
{
	destroy_images(game);
	exit (0);
}

void	lock(t_game *game)
{
	game->player.mouse_move = 0;
	mlx_mouse_hide();
}

void	delock(t_game *game)
{
	mlx_mouse_show();
	game->player.mouse_move = 1;
}
