/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pconin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 16:11:51 by pconin            #+#    #+#             */
/*   Updated: 2015/12/24 19:32:46 by pconin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static char		*ft_putn(int nbr, char *temp, int *i)
{
	if (nbr < 0)
	{
		temp[*i] = '-';
		nbr = -nbr;
		*i = *i + 1;
	}
	if (nbr >= 10)
	{
		temp = ft_putn(nbr / 10, temp, i);
		*i = *i + 1;
		temp = ft_putn(nbr % 10, temp, i);
	}
	else
		temp[*i] = nbr + '0';
	return (temp);
}

char			*ft_itoa(int n)
{
	char	temp[12];
	char	*result;
	int		i;
	int		*ptr;

	i = 0;
	ptr = &i;
	result = NULL;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	ft_putn(n, temp, ptr);
	temp[i + 1] = '\0';
	return (ft_strdup(temp));
}
