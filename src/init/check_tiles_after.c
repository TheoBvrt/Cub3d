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

static int	is_map_closed(t_map *map)
{
	int		y;
	int		x;

	y = 0;
	while (y < map->size.y)
	{
		x = 0;
		while (x < map->size.x)
		{
			if (map->tiles[y][x] == FLOOR)
			{
				if (x == 0 || x == map->size.x - 1
					|| y == 0 || y == map->size.y - 1)
					return (FALSE);
				if (map->tiles[y][x - 1] == VOID
					|| map->tiles[y][x + 1] == VOID
					|| map->tiles[y - 1][x] == VOID
					|| map->tiles[y + 1][x] == VOID)
					return (FALSE);
			}
			x++;
		}
		y++;
	}
	return (TRUE);
}

int	check_tiles_after(t_map *map)
{
	if (is_map_closed(map) == FALSE)
	{
		error_print("Map is not closed");
		return (ERROR);
	}
	return (SUCCESS);
}
