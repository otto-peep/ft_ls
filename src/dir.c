/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pconin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/16 12:25:52 by pconin            #+#    #+#             */
/*   Updated: 2016/08/16 13:26:32 by pconin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	my_opendir(const char *path, DIR **rep)
{
	if ((*rep = opendir(path)) == NULL)
	{
		ft_putstr("ls: ");
		perror(path);
		return (0);
	}
	else
		return (1);
}

int		my_closedir(const char *path, DIR **rep)
{
	if ((closedir(*rep)) < 0)
	{
		ft_putstr("ls: ");
		perror(path);
		return (0);
	}
	*rep = NULL;
	return (1);
}
