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

#include "../header.h"

int	check_args(int argc, char **argv, t_carte *carte)
{
	int	fd;

	if (argc == 1)
		my_exit("No map\n", carte);
	if (argc > 2)
		my_exit("Too many arguments\n", carte);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		close(fd);
		if (errno == EACCES)
			my_exit("permission problem with map\n", carte);
		else
			my_exit("map doesn't exist\n", carte);
	}
	return (fd);
}

void	split_free(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

unsigned int	color_from_rgb(unsigned char r, \
unsigned char g, unsigned char b)
{
	t_rgb				color;
	unsigned char		*ptr;

	color = 0x00000000;
	ptr = (unsigned char *)&color;
	ptr[2] = r;
	ptr[1] = g;
	ptr[0] = b;
	return (color);
}
