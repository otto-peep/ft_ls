/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pconin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 14:43:40 by pconin            #+#    #+#             */
/*   Updated: 2016/01/11 14:27:38 by pconin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_sign(const char *str, int i)
{
	while (str[i] == '+' || str[i] == '-')
	{
		i++;
		if (str[i] == '+' || str[i] == '-')
			return (0);
	}
	return (i);
}

int			ft_atoi(const char *str)
{
	int i;
	int ret;
	int correc;

	i = 0;
	ret = 0;
	correc = 1;
	while (str[i] == '\v' || str[i] == '\r' || str[i] == '\f'
			|| str[i] == '\t' || str[i] == '\n' || str[i] == ' ')
		i++;
	if (str[i] == '-')
		correc = -1;
	i = ft_sign(str, i);
	while (str[i] != '\0')
	{
		if (str[i] >= 48 && str[i] <= 57)
			ret = (ret * 10) + (str[i] - 48);
		if (str[i] > '9' || str[i] < '0')
			return (ret * correc);
		i++;
	}
	return (ret * correc);
}
