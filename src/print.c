/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pconin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/03 11:17:13 by pconin            #+#    #+#             */
/*   Updated: 2016/05/19 18:51:06 by pconin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
void	print_l(t_fil *file)
{
	ft_putchar(file->typ);
	ft_putstr(file->rgh);
	ft_putstr("\t");
	ft_putnbr(file->links);
	ft_putstr("\t");
	ft_putstr(file->us_name);
	ft_putstr("\t");
	ft_putstr(file->gr_name);
	ft_putstr("\t");
	if (file->typ != 'c' && file->typ != 'b')
		ft_putnbr(file->size);
	else
	{
		ft_putnbr(file->maj);
		ft_putstr(",\t");
		ft_putnbr(file->min);
	}
	ft_putstr("\t");
	ft_putstr(file->date_m);
	ft_putstr("\t");
}
void	total_blocks(t_fil *file, t_mem *s)
{
	int total;

	total = 0;
	while (file)
	{
		if (file->hide == 1 && s->a == 0)
			;
		else
			total = total + file->bloc;
		file = file->next;
	}
	ft_putstr("total ");
	ft_putnbr(total);
	ft_putstr("\n");
}

void	ft_print_path(char *path)
{
	ft_putstr("\n");
	if (ft_strcmp(path, ".") != 0)
	{
		if (path[1] == '/')
			ft_putstr(ft_strsub(path, 1, ft_strlen(path)));
		else
			ft_putstr(path);
		ft_putstr(":\n");
	}
}

void	ft_print_link(t_fil *file)
{
	ft_putstr(" -> ");
	ft_putstr(file->link);
}

void	print_dir(t_fil *file, t_mem *s, char *path, int bool)
{
	t_fil *tmp;

	if ((s->nb_file > 1 || s->R == 1) && bool == 0)
		ft_print_path(path);
	if (s->l == 1 && bool == 0)
		total_blocks(file, s);
	while (file)
	{
		if (s->a == 1 || file->hide == 0)
		{
			if (s->l == 1)
				print_l(file);
			ft_putstr(file->name);
			if (file->typ == 'l' && s->l == 1)
				ft_print_link(file);
			ft_putstr("\n");
		}
		if (bool == 1)
			break;
		tmp = file->next;
//		free(file);
		file = tmp;
	}
}
