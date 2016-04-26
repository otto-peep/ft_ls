/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printbits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pconin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 15:39:18 by pconin            #+#    #+#             */
/*   Updated: 2015/12/13 14:56:02 by pconin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_printbits(unsigned char octet)
{
	int i;
	int a;

	a = 8;
	i = 256;
	while (a > 0)
	{
		i = i / 2;
		if (octet >= i)
		{
			write(1, "1", 1);
			octet = octet - i;
		}
		else if (octet < i)
			write(1, "0", 1);
		a--;
	}
	return ;
}
