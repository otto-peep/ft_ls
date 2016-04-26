/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pconin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 18:11:42 by pconin            #+#    #+#             */
/*   Updated: 2015/12/13 15:39:56 by pconin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f) (unsigned int, char))
{
	char			*str;
	unsigned int	a;
	unsigned int	i;

	i = 0;
	str = NULL;
	if (s && f)
	{
		a = (char)ft_strlen(s);
		str = (char *)malloc(sizeof(char) * (a + 1));
		if (str == NULL)
			return (NULL);
		while (i != a)
		{
			str[i] = f(i, s[i]);
			i++;
		}
		str[i] = '\0';
	}
	return (str);
}
