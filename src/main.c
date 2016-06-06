/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pconin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 11:33:06 by pconin            #+#    #+#             */
/*   Updated: 2016/06/06 17:27:18 by pconin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"


struct s_fil	*ft_add_file(struct dirent *fichier, char *name)
{
	t_fil		*file;
	struct stat	 buf;

	file = (t_fil *)malloc(sizeof(t_fil));
	file->path = ft_strjoin(name, "/");
	file->path = ft_strjoin(file->path, fichier->d_name);
	if ((lstat(file->path, &buf)) == -1)
		lstat(name, &buf);
	file->size = buf.st_size;
	file->name = ft_strdup(fichier->d_name);
	get_date(file, buf.st_ctimespec.tv_sec, buf.st_ctimespec.tv_nsec);
	get_rights(file, buf);
	get_type(file, buf);
	if (file->typ == 'l')
	{
		if (get_link(file, file->path) == 0)
			return (NULL);
	}
	file->bloc = buf.st_blocks;
	file->us_name = ft_strdup((getpwuid(buf.st_uid))->pw_name);
	if (getgrgid(buf.st_gid) == NULL)
		file->gr_name = ft_itoa(buf.st_gid);
	else
		file->gr_name = ft_strdup((getgrgid(buf.st_gid)->gr_name));
	file->hide = 0;
	if (file->name[0] == '.' )
		file->hide = 1;
	file->links = buf.st_nlink;
	file->next = NULL;
	return (file);
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

int		ft_only_one(t_mem *s, t_fil *file, char *fname)
{
	while (file)
	{
		if (ft_strcmp(file->name, fname) == 0)
		{
			print_dir(file, s, ".", 1);
			return (1);
		}
		file = file->next;
	}
	return (0);
}


void	ls_rec(t_mem *s, char *path)
{
	DIR *rep = NULL;
	struct dirent *fichier = NULL;
	t_fil *tail;
	t_fil *file;
	int		bool;

	bool = 0;
	file = NULL;
	fichier = malloc(sizeof(struct dirent));
	rep = malloc (sizeof(DIR));
	if ((rep = opendir(path)) == NULL)
	{
		rep = opendir(".");
		bool = 1;
	}
	while ((fichier = readdir(rep)) != NULL)
	{
		if (file == NULL)
			file = ft_add_file(fichier, path);
		else
		{
			tail = file;
			while (tail->next)
				tail = tail->next;
			tail->next = ft_add_file(fichier, path);
		}
	}
	if (bool == 1)
	{
		if (ft_only_one(s, file, path) == 0)
		{
			ft_putstr("ls :");
			perror(path);
			return ;
		}
	}
	if (closedir(rep) == -1)
		perror("error");
	if (bool == 0)
	{
		ft_flags(&file, s);
		print_dir(file, s, path, 0);
		if (s->R == 1)
			parse_for_rec(s, file);
	}
	free(fichier);
}

int		main(int argc, char **argv)
{
	t_mem *s;
	s = (t_mem *)malloc(sizeof(t_mem));
	parse_arg(argv, s);
	int i;

	i = 0;
	DIR* rep = NULL;
	struct dirent	*fichier = NULL;
	fichier = malloc(sizeof(struct dirent));
	rep = malloc(sizeof(DIR));
	while (s->files[i] != NULL)
	{
		ls_rec(s, s->files[i]);
		i++;
	}
	free(s);
	return (0);
}
