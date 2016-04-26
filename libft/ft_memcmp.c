/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pconin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 19:40:25 by pconin            #+#    #+#             */
/*   Updated: 2016/01/11 14:33:54 by pconin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*src;
	unsigned char	*dst;
	size_t			i;

	i = 0;
	src = (unsigned char *)s1;
	dst = (unsigned char *)s2;
	while (n > i)
	{
		if (src[i] != dst[i])
			return (src[i] - dst[i]);
		i++;
	}
	return (0);
}
