/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_colors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouvera <tbouvera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 11:59:56 by jmorcom-          #+#    #+#             */
/*   Updated: 2024/03/08 13:32:22 by tbouvera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

static int	set_into_color(char *color_str, unsigned int *rgb)
{
	char		**split;

	split = ft_split(color_str, ',');
	if (split == NULL)
	{
		error_print("malloc error");
		exit(1);
	}
	if (split[0] == NULL
		|| split[1] == NULL || split[2] == NULL || split[3] != NULL)
	{
		error_print("color format error");
		split_free(split);
		return (ERROR);
	}
	*rgb = color_from_rgb(ft_atoi(split[0]), \
							ft_atoi(split[1]), \
							ft_atoi(split[2]));
	split_free(split);
	return (SUCCESS);
}

int	set_colors(char **lines, t_map *map, int first_line)
{
	char	*floor_color;
	char	*ceiling_color;
	int		result;

	floor_color = get_info_by_id("F ", lines, first_line);
	if (floor_color == NULL)
		return (ERROR);
	ceiling_color = get_info_by_id("C ", lines, first_line);
	if (ceiling_color == NULL)
	{
		error_print("ceiling color not found");
		free(floor_color);
		return (ERROR);
	}
	result = SUCCESS;
	if (set_into_color(floor_color, &map->floor_color) == ERROR)
		result = ERROR;
	if (set_into_color(ceiling_color, &map->ceiling_color) == ERROR)
		result = ERROR;
	free(floor_color);
	free(ceiling_color);
	return (result);
}
