/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pconin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 16:09:38 by pconin            #+#    #+#             */
/*   Updated: 2015/12/13 18:14:38 by pconin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*str;

	str = NULL;
	str = (char *)ft_memalloc(size + 1);
	if (str == NULL)
		return (NULL);
	else
	{
		ft_bzero(str, size + 1);
		return (str);
	}
}
