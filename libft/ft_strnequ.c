/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pconin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 18:31:31 by pconin            #+#    #+#             */
/*   Updated: 2015/12/08 16:47:26 by pconin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t	a;

	a = 0;
	if (s1 && s2 && n > 0)
	{
		while (s1[a] == s2[a] && s1[a] && s2[a] && a < (n - 1))
			a++;
		if (s1[a] == s2[a])
			return (1);
		else
			return (0);
	}
	else if (n == 0)
		return (1);
	else
		return (0);
}
