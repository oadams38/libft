/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oladams <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 16:34:18 by oladams           #+#    #+#             */
/*   Updated: 2023/04/08 18:11:48 by oladams          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_n_words(char const *s, char c)
{
	size_t	i;
	size_t	n_words;

	n_words = 0;
	if (s[0] == '\0')
		return (n_words);
	if (s[0] != c)
		n_words++;
	i = 1;
	while (s[i])
	{
		if (s[i] != c && s[i - 1] == c)
			n_words++;
		i++;
	}
	return (n_words);
}

static size_t	len_wd(char const *s, size_t i, char c)
{
	size_t	j;

	j = 0;
	while (s[i + j] && s[i + j] != c)
		j++;
	return (j);
}

static char	**free_tab(char **tab, size_t k)
{
	size_t	i;

	i = 0;
	while (i < k)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

static char	**fill_me_please(char **tab, char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	k;

	k = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			tab[k] = (char *) malloc(sizeof(char) * (len_wd(s, i, c) + 1));
			if (!tab[k])
				return (free_tab(tab, k));
			j = 0;
			while (s[i] && s[i] != c)
				tab[k][j++] = s[i++];
			tab[k][j] = '\0';
			k++;
		}
		else
			i++;
	}
	tab[k] = NULL;
	return (tab);
}

char	**ft_split(char const *s, char c)
{
	size_t	n_words;
	char	**tab;

	if (!s)
		return (NULL);
	n_words = get_n_words(s, c);
	tab = (char **) malloc(sizeof(char *) * (n_words + 1));
	if (!tab)
		return (NULL);
	return (fill_me_please(tab, s, c));
}
