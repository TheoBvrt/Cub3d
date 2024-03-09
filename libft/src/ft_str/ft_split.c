/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorcom- <jmorcom-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 08:36:03 by jmorcom-          #+#    #+#             */
/*   Updated: 2023/07/15 17:40:59 by jmorcom-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

typedef struct s_word {
	int	pos;
	int	len;
}	t_word;

static void	*free_all(char ***res)
{
	int	i;

	i = 0;
	while ((*res)[i] != NULL)
	{
		free((*res)[i]);
		i++;
	}
	free(*res);
	return (NULL);
}

static int	index_words(char const *s, char c, t_word *words)
{
	int	i_char;
	int	i_word;

	i_char = 0;
	i_word = 0;
	while (s[i_char] != '\0')
	{
		if (s[i_char] == c)
			i_char++;
		else if (s[i_char] != c)
		{
			words[i_word].pos = i_char;
			while (s[i_char] != c && s[i_char] != '\0')
				i_char++;
			words[i_word].len = i_char - words[i_word].pos;
			i_word++;
		}
	}
	return (i_word);
}

char	**ft_split(char const *s, char c)
{
	t_word	words[2048];
	int		n_word;
	int		i_word;
	char	**res;

	n_word = index_words(s, c, words);
	res = malloc((n_word + 1) * sizeof(char *));
	if (res == NULL)
		return (NULL);
	i_word = 0;
	while (i_word < n_word)
	{
		res[i_word] = ft_substr(s, words[i_word].pos, words[i_word].len);
		if (res[i_word] == NULL)
			return (free_all(&res));
		i_word++;
	}
	res[i_word] = NULL;
	return (res);
}
