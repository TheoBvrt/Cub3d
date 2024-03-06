/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouvera <tbouvera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 11:52:58 by tbouvera          #+#    #+#             */
/*   Updated: 2022/10/18 10:43:07 by tbouvera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../cub3d.h"

int	check_file(char *map)
{
	int	fd;

	fd = open("map.cub3d", O_RDONLY);
	if (fd < 0)
		ft_printf ("Error\nFichier invalide !");
	return (fd);
}

void	map_parsing(char **tab, t_game *game)
{
	int		i;
	int		fd;
	char	*tmp;
	char	*line;

	i = 0;
	fd = open(game->map.map_path, O_RDONLY);
	while (i < game->map.height)
	{
		line = get_next_line(fd);
		tmp = ft_strdup(line);
		free (line);
		if (tmp[ft_strlen(tmp) - 1] == '\n')
			tmp[ft_strlen(tmp) - 1] = '\0';
		tab[i] = ft_strdup(tmp);
		i ++;
		free (tmp);
	}
	close (fd);
}

void	print_tab(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < game->map.height)
	{
		ft_printf("\n");
		while (x < game->map.width)
		{
			ft_printf("%c", game->map.tab[y][x]);
			x ++;
		}
		x = 0;
		y ++;
	}
}

int	checker(t_game *game, char *maps)
{
	char	**tab;
	game->map.height = get_map_height(game);
	game->map.width = get_map_width(game);
	tab = ft_calloc(sizeof (char *), (game->map.height + 1));
	if (!tab)
		return (1);
	game->map.tab = tab;

	ft_printf("%d x ", game->map.height);
	ft_printf("%d", game->map.width);

	map_parsing(game->map.tab, game);
	print_tab(game);
	return (0);
}