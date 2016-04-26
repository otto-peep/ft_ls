/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pconin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 16:08:23 by pconin            #+#    #+#             */
/*   Updated: 2016/01/11 14:48:44 by pconin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t len;
	size_t a;

	a = 0;
	len = ft_strlen(s1);
	while (s2[a] && a < n)
	{
		s1[len + a] = s2[a];
		a++;
	}
	s1[len + a] = '\0';
	return (s1);
}
