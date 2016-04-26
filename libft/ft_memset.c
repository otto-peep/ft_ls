/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pconin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 15:50:48 by pconin            #+#    #+#             */
/*   Updated: 2016/01/11 14:36:04 by pconin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*temp;
	size_t			count;

	temp = (unsigned char *)b;
	count = 0;
	while (count < len)
	{
		temp[count] = (unsigned char)c;
		count++;
	}
	return (b);
}
