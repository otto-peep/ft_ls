/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pconin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/03 11:19:22 by pconin            #+#    #+#             */
/*   Updated: 2016/08/21 21:55:11 by pconin           ###   ########.fr       */
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
	s->l = 0;
	s->rec = 0;
	s->a = 0;
	s->r = 0;
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
		s->f_sort = &(tri_date);
	else
	{
		ft_putstr("ls: illegal option -- ");
		ft_putchar(c);
		ft_putstr(
		"\nusage: ls [-ABCFGHLOPRSTUWabcdefghiklmnopqrstuwx1] [file ...]\n");
		exit(0);
	}
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

	i = 1;
	init_arg(s);
	while (argv[i])
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
		i++;
	}
	if (s->files == NULL)
		ft_add_arg(s, argv, i, 1);
}
