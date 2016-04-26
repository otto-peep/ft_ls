/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pconin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 12:32:37 by pconin            #+#    #+#             */
/*   Updated: 2016/01/11 14:40:42 by pconin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	lendst;
	size_t	lensrc;
	size_t	ind;
	size_t	ind2;
	size_t	nbchar;

	ind = 0;
	ind2 = 0;
	lendst = 0;
	nbchar = 0;
	while (dst[lendst] && lendst < size)
		lendst++;
	nbchar = size - lendst;
	lensrc = ft_strlen(src);
	while (dst[ind] != '\0')
		ind++;
	while (ind + ind2 < size - 1 && src[ind2] != '\0' && ind2 < nbchar)
	{
		dst[ind + ind2] = src[ind2];
		ind2++;
	}
	dst[ind + ind2] = '\0';
	return (lensrc + lendst);
}
