/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pconin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 15:06:53 by pconin            #+#    #+#             */
/*   Updated: 2016/01/11 14:35:00 by pconin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;
	size_t			a;

	a = 0;
	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	if (dest > src)
	{
		a = n;
		while (n--)
		{
			a--;
			d[a] = s[a];
		}
	}
	else
		ft_memcpy(dest, src, n);
	return (dest);
}
