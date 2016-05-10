/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pconin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 11:33:06 by pconin            #+#    #+#             */
/*   Updated: 2016/05/10 15:11:21 by pconin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"


struct s_fil	*ft_add_file(DIR *rep, struct dirent *fichier, t_mem *s, char *name)
{
	t_fil		*file;
	struct stat	 buf;
	char *path;
	file = (t_fil *)malloc(sizeof(t_fil));
	path = ft_strjoin(name, "/");
	path = ft_strjoin(path, fichier->d_name);
	file->path = ft_strjoin(name, "/");
	file->path = ft_strjoin(file->path, fichier->d_name);
	if ((lstat(file->path, &buf)) == -1)
		lstat(name, &buf);
	file->size = buf.st_size;
	file->name = fichier->d_name;
	get_date(file, buf.st_ctime);
	get_rights(file, buf);
	get_type(file, buf);
	file->bloc = buf.st_blocks;
	file->us_name = (getpwuid(buf.st_uid))->pw_name;
	if (getgrgid(buf.st_gid) == NULL)
		file->gr_name = ft_itoa(buf.st_gid);
	else
		file->gr_name = (getgrgid(buf.st_gid)->gr_name);
	file->hide = 0;
	if (file->name[0] == '.')
		file->hide = 1;
	file->links = buf.st_nlink;
	if (file->typ == 'r')
		printf("%s\n", file->path);
	file->next = NULL;

	return (file);
}

void	ls_rec(t_mem *s, char *path)
{
	DIR *rep = NULL;
	struct dirent *fichier = NULL;
	t_fil *tail;
	t_fil *file;

	file = NULL;
	sleep(1);
	fichier = malloc(sizeof(struct dirent));
	rep = malloc (sizeof(DIR));
	if ((rep = opendir(path)) == NULL)
	{
		perror("error");
		return ;
	}
	while ((fichier = readdir(rep)) != NULL)
	{
		if (file == NULL)
			file = ft_add_file(rep, fichier, s, path);
		else
		{
			tail = file;
			while (tail->next)
				tail = tail->next;
			tail->next = ft_add_file(rep, fichier, s, path);
			if (s->r == 1 && tail->next->typ == 'd' && tail->next->hide == 0)
			{
				ft_putendl(tail->next->path);
			//	ls_rec(s, tail->next->path);
			}
		}
	}
	if (closedir(rep) == -1)
		perror("error");
	print_dir(file, s);
}

int		main(int argc, char **argv)
{
	t_mem *s;
	t_fil	*file;
	s = (t_mem *)malloc(sizeof(t_mem));
	parse_arg(argv, s);
	t_fil *tail;

	DIR* rep = NULL;
	struct dirent	*fichier = NULL;
	fichier = malloc(sizeof(struct dirent));
	rep = malloc(sizeof(DIR));
	s->dat = NULL;
	if ((rep = opendir(s->arg)) == NULL)
	{
		perror("error");
		exit(0);
	}
	while ((fichier = readdir(rep)) != NULL)
	{
		if (s->dat == NULL)
			s->dat = ft_add_file(rep, fichier, s, s->arg);
		else
		{
			tail = s->dat;
			while (tail->next)
				tail = tail->next;
			tail->next = ft_add_file(rep, fichier, s, s->arg);
			if (s->r == 1 && tail->next->typ == 'd' && tail->next->hide == 0)
			{
				printf("%s", tail->next->path);
				ls_rec(s, tail->next->path);
			}
		}
	}
	if (closedir(rep) == -1)
		perror("error");
	ft_flags(&s->dat, s);
	print_dir(s->dat, s);
	return (0);
}
