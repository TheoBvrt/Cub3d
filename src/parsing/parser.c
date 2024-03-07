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

int	is_good_char(char c)
{
	if (c != '0' && c != '1' && c != '-')
		return (1);
	else
		return (0);
}

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
	int		x;
	int		fd;
	char	*tmp;
	char	*line;

	i = 0;
	x = 0;
	fd = open(game->map.map_path, O_RDONLY);
	while (i < game->map.height)
	{
		line = get_next_line(fd);
		tmp = ft_strdup(line);
		free (line);
		if (tmp[ft_strlen(tmp) - 1] == '\n')
			tmp[ft_strlen(tmp) - 1] = '\0';
		while(x < game->map.width && tmp[x] != '\0')
		{
			if (is_good_char(tmp[x]) == 0)
				tab[i][x] = tmp[x];
			else
				tab[i][x] = '-';
			x ++;
		}
		x = 0;
		i ++;
		free (tmp);
	}
	close (fd);
}

int	checker_tab(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < game->map.height)
	{
		while (x < game->map.width)
		{
			if (is_good_char(game->map.tab[y][x]) == 1)
				return (1);
			x ++;
		}
		x = 0;
		y ++;
	}
	return (0);
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
	int 	i;

	i = 0;
	game->map.height = get_map_height(game);
	game->map.width = get_map_width(game);
	tab = ft_calloc(sizeof (char *), (game->map.height + 1));
	if (!tab)
		return (1);
	while (i < game->map.height)
		tab[i ++] = ft_calloc(sizeof(char), game->map.width + 1);
	game->map.tab = tab;
	set_tab_default(game);
	map_parsing(game->map.tab, game);
	print_tab(game);
	if (checker_tab(game) == 1)
		exit (1);
	return (0);
}