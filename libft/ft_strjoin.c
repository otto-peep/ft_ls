/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pconin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 17:35:17 by pconin            #+#    #+#             */
/*   Updated: 2015/12/07 14:26:39 by pconin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		size;
	char	*rtn;

	if (!s1 && !s2)
		return (NULL);
	if (s1 && s2)
	{
		size = ft_strlen(s1) + ft_strlen(s2);
		rtn = (char *)malloc(sizeof(char) * (size + 1));
		if (rtn == NULL)
			return (NULL);
		ft_strcpy(rtn, s1);
		ft_strcat(rtn, s2);
		return (rtn);
	}
	if (s1 && !s2)
		return (ft_strdup(s1));
	else
		return (ft_strdup(s2));
}
