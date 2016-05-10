/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pconin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/03 11:19:22 by pconin            #+#    #+#             */
/*   Updated: 2016/05/10 11:46:28 by pconin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_error(char *str)
{
	ft_putstr(str);
	exit(0);
}

void	init_arg(t_mem *s)
{
  s->l = 0;
  s->R = 0;
  s->a = 0;
  s->r = 0;
  s->t = 0;
}

void	check_flag(t_mem *s, char c)
{
	if (c == 'l')
		s->l = 1;
	else if (c == 'R')
		s->R = 1;
	else if (c == 'a')
		s->a = 1;
	else if (c == 'r')
		s->r = 1;
	else if (c == 't')
		s->t = 1;
	else
	{
		ft_putstr("ls: illegal option -- Z\n");
		ft_error("[-ABCFGHLOPRSTUWabcdefghiklmnopqrstuwx1] [file ...]");
	}
}

void	parse_arg(char **argv, t_mem *s)
{
	int i;
	int a;

	s->arg = NULL;
	i = 1;
	init_arg(s);
	while (argv[i])
	{
		if (argv[i][0] == '-')
		{
			a = 1;
			while (argv[i][a])
			{
				check_flag(s, argv[i][a]);
				a++;
			}
		}
		else
			s->arg = ft_strdup(argv[i]);
		i++;
	}
	if (s->arg == NULL)
		s->arg = ft_strdup("./");
}
