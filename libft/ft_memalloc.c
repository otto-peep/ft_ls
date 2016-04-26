/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pconin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 17:25:33 by pconin            #+#    #+#             */
/*   Updated: 2015/12/24 20:33:56 by pconin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_memalloc(size_t size)
{
	unsigned char *fresh;

	if (size == 0)
		return (NULL);
	fresh = (unsigned char *)malloc(sizeof(unsigned char) * size);
	if (fresh == NULL)
		return (NULL);
	ft_bzero(fresh, size);
	return ((void *)fresh);
}
