/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pconin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 16:57:13 by pconin            #+#    #+#             */
/*   Updated: 2015/12/24 19:59:31 by pconin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*dst;
	size_t	index;

	index = 0;
	if (!s)
		return (NULL);
	dst = NULL;
	dst = (char *)ft_memalloc(len + 1);
	if (dst == NULL)
		return (NULL);
	while (index != len)
	{
		dst[index] = s[start + index];
		index++;
	}
	dst[index] = '\0';
	return (dst);
}
