/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pconin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/16 12:25:52 by pconin            #+#    #+#             */
/*   Updated: 2016/08/24 17:25:46 by pconin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		my_opendir(char *path, DIR **rep, t_mem *s)
{
	if ((*rep = opendir(path)) == NULL)
	{
		if (s->only == 1)
		{
			s->only = 0;
			ft_error((char *)path);
		}
		else
		{
			s->only = 1;
			if (ft_lastchr((char *)path, '/') <= 0)
				ls_rec(s, "./");
			else
				ls_rec(s, ft_strsub(path, 0, ft_lastchr(path, '/')));
		}
		return (0);
	}
	else
		return (1);
}

int		my_closedir(const char *path, DIR **rep)
{
	if ((closedir(*rep)) < 0)
	{
		ft_error((char *)path);
		return (0);
	}
	*rep = NULL;
	return (1);
}

void	wrong_flag(char c)
{
	ft_putstr("ls: illegal option -- ");
	ft_putchar(c);
	ft_putstr(
			"\nusage: ls [-lRartSfinoUu] [file ...]\n");
	exit(0);
}
