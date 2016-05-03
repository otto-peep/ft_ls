/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pconin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 11:33:06 by pconin            #+#    #+#             */
/*   Updated: 2016/05/02 18:40:03 by pconin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	parse_arg(char **argv, t_mem *s)
{
	int i;

	s->arg = NULL;
	i = 0;
	while (argv[i])
	{
		if (ft_strcmp(argv[i], "-l") == 0)
			s->l = 1;
		if (ft_strcmp(argv[i], "-R") == 0)
			s->R = 1;
		if (ft_strcmp(argv[i], "-a") == 0)
			s->a = 1;
		if (ft_strcmp(argv[i], "-r") == 0)
			s->r = 1;
		if (ft_strcmp(argv[i], "-t") == 0)
			s->t = 1;
		else
			s->arg = ft_strdup(argv[i]);
		i++;
	}
}

void			print_dir(t_fil *file, t_mem *s)
{
	int i;

	while (file)
	{
		if (s->l == 1)
		{
			ft_putstr(file->us_name);
			ft_putstr("\t");
			ft_putstr(file->gr_name);
			ft_putstr("\t");
			ft_putnbr(file->size);
			ft_putstr("\t");
			ft_putstr(file->date_m);
			ft_putstr("\t");
			ft_putstr(file->name);
			ft_putstr("\n");
		}
		file = file->next;
	}
}


struct s_fil	*ft_add_file(DIR *rep, struct dirent *fichier)
{
	t_fil		*file;
	struct stat	*buf;
	
	buf = malloc(sizeof(struct stat));
	lstat(fichier->d_name, buf);
	file = (t_fil *)malloc(sizeof(t_fil));
	file->size = buf->st_size;
	file->name = fichier->d_name;
	file->date_m = ft_strdup(ctime(&buf->st_mtime));
	file->us_name = (getpwuid(buf->st_uid))->pw_name;
	file->gr_name = (getgrgid(buf->st_gid))->gr_name;
	file->next = NULL;
	return (file);
}

int		main(int argc, char **argv)
{
	t_mem *s;
	t_fil	*tail;
	s = (t_mem *)malloc(sizeof(t_mem));
	if (argc < 2)
		exit(0);
	parse_arg(argv, s);
	
	DIR* rep = NULL;
	struct dirent	*fichier = NULL;

	s->dat = NULL;
	if ((rep = opendir(s->arg)) == NULL)
		perror("error");
	while ((fichier = readdir(rep)) != NULL)
	{
		if (s->dat == NULL)
			s->dat = ft_add_file(rep, fichier);
		else
		{
			tail = s->dat;
			while (tail->next)
				tail = tail->next;
			tail->next = ft_add_file(rep, fichier);
		}
	}
	if (closedir(rep) == -1)
		perror("error");
	print_dir(s->dat, s);
	return (0);
}
