/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouvera <tbouvera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 11:54:23 by tbouvera          #+#    #+#             */
/*   Updated: 2022/10/18 10:42:40 by tbouvera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_word_parsing(char const *str, char c)
{
	int	word_count;
	int	i;

	word_count = 0;
	i = 0;
	while (str[i] != 0)
	{
		if (str[i] != c && (str[i + 1] == c || str[i + 1] == 0))
			word_count++;
		i++;
	}
	return (word_count);
}

static int	ft_size_of_tab(char **ptr, const char *s, char c, int max_word)
{
	int		size;
	int		i;
	int		index;

	size = 0;
	i = 0;
	index = 0;
	while (i < max_word)
	{
		while (s[index] == c)
			index ++;
		while (s[index] != c && s[index++] != 0)
			size ++;
		ptr[i] = ft_calloc (sizeof(char), (size + 1));
		if (!ptr[i])
			return (0);
		size = 0;
		i++;
	}
	return (1);
}

static void	ft_asign_char(char **ptr, const char *s, char c, int max_word)
{
	int		size;
	int		i;
	int		index;

	size = 0;
	i = 0;
	index = 0;
	while (i < max_word)
	{
		while (s[index] == c)
			index ++;
		while (s[index] != c && s[index] != 0)
			ptr[i][size++] = s[index++];
		size = 0;
		i++;
	}
}

char	**ft_split(char const *s, char c)
{
	char	**ptr;
	int		max_word;

	max_word = 0;
	ptr = ft_calloc (sizeof(char *), ft_word_parsing(s, c) + 1);
	if (!ptr)
		return (NULL);
	if (!s)
		return (NULL);
	max_word = ft_word_parsing(s, c);
	if (!ft_size_of_tab(ptr, s, c, max_word))
		return (NULL);
	ft_asign_char(ptr, s, c, max_word);
	return (ptr);
}
