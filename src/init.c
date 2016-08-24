/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pconin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/03 11:19:22 by pconin            #+#    #+#             */
/*   Updated: 2016/08/23 17:35:20 by pconin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_error(char *str)
{
	ft_putstr("ft_ls: ");
	perror(str);
}

void	init_arg(t_mem *s)
{
	s->only = 0;
	s->u = 'x';
	s->n = 0;
	s->i = 0;
	s->l = 0;
	s->rec = 0;
	s->a = 0;
	s->r = 0;
	s->f = 0;
	s->t = 0;
	s->s = 0;
	s->o = 0;
	s->f_sort = &(tri_ascii);
	s->files = NULL;
	s->nb_file = 1;
}

void	check_flag(t_mem *s, char c)
{
	if (c == 'l')
		s->l = 1;
	else if (c == 'R')
		s->rec = 1;
	else if (c == 'a')
		s->a = 1;
	else if (c == 'r')
		s->r = 1;
	else if (c == 't')
		s->t = 1;
	else if (c == 'S')
		s->s = 1;
	else if (c == 'f')
		s->f = 1;
	else if (c == 'i')
		s->i = 1;
	else if (c == 'n')
		s->n = 1;
	else if (c == 'o')
		s->o = 1;
	else if (c == 'u' || c == 'U')
		s->u = c;
	else
		wrong_flag(c);
}

void	ft_add_arg(t_mem *s, char **argv, int i, int bool)
{
	int size;

	size = i;
	if (bool == 1)
	{
		s->files = (char **)malloc(sizeof(char *) * (2));
		s->files[0] = ft_strdup(".");
		s->files[1] = NULL;
	}
	else
	{
		while (argv[size])
			size++;
		size = size - i;
		s->nb_file = size;
		s->files = (char **)malloc(sizeof(char *) * (size + 1));
		s->files[size] = NULL;
		size = 0;
		while (argv[i])
		{
			s->files[size] = ft_strdup(argv[i]);
			size++;
			i++;
		}
	}
}

void	parse_arg(char **argv, t_mem *s)
{
	int i;
	int a;

	i = 0;
	init_arg(s);
	while (argv[++i])
	{
		if (argv[i][0] == '-' && argv[i][1] != '\0')
		{
			a = 1;
			while (argv[i][a])
			{
				check_flag(s, argv[i][a]);
				a++;
			}
		}
		else
		{
			ft_add_arg(s, argv, i, 0);
			break ;
		}
	}
	ft_priority(s);
	if (s->files == NULL)
		ft_add_arg(s, argv, i, 1);
}
