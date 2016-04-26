/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pconin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/05 14:53:58 by pconin            #+#    #+#             */
/*   Updated: 2015/12/24 19:34:53 by pconin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

static int	words_nb(const char *s, char c)
{
	int	i;

	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s && *s != c)
		{
			i++;
			while (*s && *s != c)
				s++;
		}
	}
	return (i);
}

static int	word_len(const char *s, char c)
{
	int	i;

	i = 0;
	while (*s != c && *s)
	{
		i++;
		s++;
	}
	return (i);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		x;
	int		y;
	int		nbword;

	x = 0;
	y = 0;
	if (!s || !c)
		return (NULL);
	nbword = words_nb(s, c);
	tab = (char**)malloc(sizeof(char*) * nbword + 1);
	if (tab == NULL)
		return (NULL);
	while (x < nbword && s[y])
	{
		while (s[y] == c && s[y])
			y++;
		tab[x] = ft_strsub(&s[y], 0, word_len(&s[y], c));
		y = y + word_len(&s[y], c);
		x++;
	}
	tab[x] = NULL;
	return (tab);
}
