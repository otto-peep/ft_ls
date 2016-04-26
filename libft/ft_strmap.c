/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pconin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 17:12:15 by pconin            #+#    #+#             */
/*   Updated: 2015/12/13 15:39:40 by pconin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*str;
	int		a;
	int		i;

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
			str[i] = f(s[i]);
			i++;
		}
		str[i] = '\0';
	}
	return (str);
}
