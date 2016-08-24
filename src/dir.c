/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pconin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/16 12:25:52 by pconin            #+#    #+#             */
/*   Updated: 2016/08/24 17:57:20 by pconin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		my_opendir(char *p, DIR **rep, t_mem *s)
{
	if ((*rep = opendir(p)) == NULL)
	{
		if (s->only == 1)
		{
			s->only = 0;
			ft_error((char *)p);
		}
		else
		{
			s->only = 1;
			if (ft_lastchr((char *)p, '/') <= 0)
			{
				s->oldpath = ft_strsub(p, ft_lastchr(p, '/'), ft_strlen(p));
				ls_rec(s, "./");
			}
			else
			{
				s->oldpath = ft_strsub(p, ft_lastchr(p, '/') + 1, ft_strlen(p));
				ls_rec(s, ft_strsub(p, 0, ft_lastchr(p, '/')));
			}
		}
		return (0);
	}
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
