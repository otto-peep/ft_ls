/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pconin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 19:24:45 by pconin            #+#    #+#             */
/*   Updated: 2016/01/11 14:32:27 by pconin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	size_t			a;

	a = 0;
	str = (unsigned char *)s;
	while (a < n)
	{
		if (str[a] != (unsigned char)c)
			a++;
		else
			return (&str[a]);
	}
	return (NULL);
}
