/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouvera <tbouvera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 11:59:56 by jmorcom-          #+#    #+#             */
/*   Updated: 2024/03/08 13:04:41 by tbouvera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

static void	set_map_size(char **lines, t_map *map)
{
	int		largest_x;
	int		i;

	map->size.y = 0;
	while (lines[map->size.y] != NULL)
		map->size.y++;
	largest_x = 0;
	i = 0;
	while (lines[i] != NULL)
	{
		if ((int)ft_strlen(lines[i]) > largest_x)
			largest_x = ft_strlen(lines[i]);
		i++;
	}
	map->size.x = largest_x;
}

static void	allocate_tiles(t_map *map)
{
	int		i;

	map->tiles = (char **)malloc(sizeof(char *) * map->size.y);
	if (map->tiles == NULL)
	{
		error_print("malloc error");
		exit(1);
	}
	i = 0;
	while (i < map->size.y)
	{
		map->tiles[i] = (char *)ft_calloc(map->size.x, sizeof(char));
		if (map->tiles[i] == NULL)
		{
			error_print("malloc error");
			exit(1);
		}
		i++;
	}
}

static int	fill_tiles(char **lines, t_carte *carte, int i, t_game *game)
{
	int		j;

	while (lines[i] != NULL)
	{
		j = 0;
		while (lines[i][j] != '\0')
		{
			if (lines[i][j] == ' ')
				carte->map.tiles[i][j] = (char) VOID;
			else if (lines[i][j] == '0')
				carte->map.tiles[i][j] = (char) FLOOR;
			else if (lines[i][j] == '1')
				carte->map.tiles[i][j] = (char) WALL;
			else
			{
				set_player_spawn(carte, i, j, lines[i][j]);
				carte->map.tiles[i][j] = (char) FLOOR;
			}
			j++;
		}
		while (j < carte->map.size.x)
			carte->map.tiles[i][j++] = (char) VOID;
		i++;
	}
	return (SUCCESS);
}

int	set_tiles(char **lines, t_carte *carte, t_game *game)
{
	t_map	*map;

	map = &carte->map;
	if (check_tiles(lines, map) == ERROR)
		return (ERROR);
	set_map_size(lines, map);
	if (map->size.x == 0 || map->size.y == 0)
		return (ERROR);
	allocate_tiles(map);
	fill_tiles(lines, carte, 0, game);
	if (check_tiles_after(map) == ERROR)
		return (ERROR);
	return (SUCCESS);
}
