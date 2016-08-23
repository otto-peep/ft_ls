/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pconin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 11:33:06 by pconin            #+#    #+#             */
/*   Updated: 2016/08/23 17:32:21 by pconin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_add_file2(t_mem *s, t_fil *file, struct stat buf, t_fil **list)
{
	if (file->typ == 'l')
	{
		if (get_link(file, file->path) == 0)
		{
			ft_error(file->path);
			return ;
		}
	}
	get_usgr(file, s, buf);
	file->bloc = buf.st_blocks;
	file->hide = 0;
	if (file->name[0] == '.')
		file->hide = 1;
	file->links = buf.st_nlink;
	file->next = NULL;
	if (*list == NULL)
		*list = file;
	else
		s->f_sort(list, file);
}

void	ft_add_file(t_mem *s, struct dirent *f, char *name, t_fil **list)
{
	t_fil		*file;
	struct stat	buf;

	file = NULL;
	file = (t_fil*)malloc(sizeof(t_fil));
	file->path = ft_strjoin(name, "/");
	file->path = ft_strjoin(file->path, f->d_name);
	if ((lstat(file->path, &buf)) < 0)
	{
		if (lstat(name, &buf) < 0)
		{
			ft_error(file->path);
			return ;
		}
	}
	file->size = buf.st_size;
	file->name = ft_strdup(f->d_name);
	get_date(file, buf, s);
	get_rights(file, buf);
	get_type(file, buf);
	file->inode = buf.st_ino;
	ft_add_file2(s, file, buf, list);
}

void	parse_for_rec(t_mem *s, t_fil *file)
{
	while (file)
	{
		if (file->typ == 'd' && file->hide == 0)
			ls_rec(s, file->path);
		else if (file->typ == 'd' && file->hide == 1 &&
				file->name[1] != '\0' && file->name[0] != '.')
			ls_rec(s, file->path);
		file = file->next;
	}
}

void	ls_rec(t_mem *s, char *path)
{
	DIR				*rep;
	struct dirent	*fichier;
	t_fil			*list;

	rep = NULL;
	list = NULL;
	if (my_opendir(path, &rep) != 0)
	{
		while ((fichier = readdir(rep)) != NULL)
			ft_add_file(s, fichier, path, &list);
		if (my_closedir(path, &rep) != 0)
		{
			if (s->r == 1)
				flag_r(&list);
			print_dir(list, s, path, 0);
			if (s->rec == 1)
				parse_for_rec(s, list);
		}
	}
}

int		main(int argc, char **argv)
{
	t_mem	s;
	int		i;

	i = 0;
	parse_arg(argv, &s);
	while (s.files[i] != NULL)
	{
		ls_rec(&s, s.files[i]);
		i++;
	}
	argc = 0;
	return (0);
}
