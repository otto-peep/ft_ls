/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pconin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 13:14:25 by pconin            #+#    #+#             */
/*   Updated: 2015/12/05 21:30:43 by pconin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strclr(char *s)
{
	unsigned int i;
	unsigned int a;

	i = 0;
	if (s)
	{
		a = ft_strlen(s);
		while (i != a)
		{
			s[i] = '\0';
			i++;
		}
	}
}
