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

static void	add_to_result(char **result, char *to_add)
{
	char	*tmp;

	if (to_add == NULL || ft_strlen(to_add) == 0)
		return ;
	if (*result == NULL)
	{
		*result = ft_strdup(to_add);
		return ;
	}
	tmp = *result;
	*result = ft_strjoin(*result, to_add);
	free(tmp);
	if (*result == NULL)
	{
		error_print("malloc error");
		exit(1);
	}
}

char	*get_all_file(char *filename)
{
	int		fd;
	char	buf[BUFF_SIZE];
	char	*result;
	int		count;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		error_print("could not open file");
		return (NULL);
	}
	result = NULL;
	while (1)
	{
		count = read(fd, buf, BUFF_SIZE - 1);
		buf[count] = '\0';
		add_to_result(&result, buf);
		if (count == 0)
			break ;
	}
	if (result == NULL || ft_strlen(result) == 0)
		error_print("file is empty");
	return (result);
}
