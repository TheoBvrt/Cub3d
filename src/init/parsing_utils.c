/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorcom- <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 11:59:56 by jmorcom-          #+#    #+#             */
/*   Updated: 2024/03/06 11:59:57 by jmorcom-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../header.h"

/* Retourner la position en double (x et y)
 * Retourner la Direction
 * Check si player est dans la map
 * */

static void	set_player_dir(char c, t_carte *carte)
{
	if (c == 'N')
		carte->map.ply_dir = NORTH;
	if (c == 'E')
		carte->map.ply_dir = EAST;
	if (c == 'W')
		carte->map.ply_dir = WEST;
	if (c == 'S')
		carte->map.ply_dir = SOUTH;
}

void	set_player_spawn(t_carte *carte, int i, int j, char c)
{
	carte->map.ply_pos.x = i;
	carte->map.ply_pos.y = j;
	set_player_dir(c, carte);
}

int	is_in_charset(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}
