/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouvera <tbouvera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 11:52:58 by tbouvera          #+#    #+#             */
/*   Updated: 2022/10/18 10:43:07 by tbouvera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../cub3d.h"

int	get_map_height(t_game *game)
{
	int height;
	int	fd;
	char	*line;

	height = 0;
	fd = open(game->map.map_path, O_RDONLY);
	line = get_next_line(fd);
	free (line);
	while (line != NULL)
	{
		line = get_next_line(fd);
		height ++;
		free (line);
	}
	close (fd);
	return (height);
}

int	get_map_width(t_game *game)
{
	int	fd;
	int		max_len;
	char	*line;
	char	*ptr;
	int		var;

	max_len = 0;
	var = 0;
	fd = open(game->map.map_path, O_RDONLY);
	line = get_next_line(fd);
	ptr = ft_strdup(line);
	max_len = ft_strlen(ptr);
	free (line);
	while (var == 0)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break;
		ptr = ft_strdup(line);
		if (ft_strlen(ptr) > max_len)
			max_len = ft_strlen(ptr);
		free (line);
	}
	close (fd);
	return (max_len - 1);
}

void	set_tab_default(t_game *game)
{
	int	i;
	int	z;

	i = 0;
	z = 0;
	while (i < game->map.height)
	{
		while (z < game->map.width)
		{
			game->map.tab[i][z] = '-';
			z ++;
		}
		z = 0;
		i ++;
	}
}