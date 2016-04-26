/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pconin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 10:17:03 by pconin            #+#    #+#             */
/*   Updated: 2016/01/11 14:45:13 by pconin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	x;
	size_t	y;
	size_t	check;

	check = ft_strlen(s2);
	x = 0;
	if (!s2[0])
		return ((char *)s1);
	while (x < n && s1[x] != '\0')
	{
		y = 0;
		while (s2[y] == s1[x + y] && s2[y])
		{
			if (x + y >= n)
				return (NULL);
			if (y == check - 1)
				return ((char*)&s1[x]);
			y++;
		}
		x++;
	}
	return (NULL);
}
