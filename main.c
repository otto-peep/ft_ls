/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pconin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 11:33:06 by pconin            #+#    #+#             */
/*   Updated: 2016/04/29 15:13:09 by pconin           ###   ########.fr       */
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
		i = 0;
		while (i++ != 5 && file)
		{
			ft_putstr(file->name);
			ft_putstr("\t");
			file = file->next;
		}
		ft_putstr("\n");
	}
}

struct s_fil	*ft_add_file(DIR *rep, struct dirent *fichier)
{
	t_fil		*file;
	struct stat	*buf;
	time_t t;
	buf = malloc(sizeof(struct stat));
	lstat(fichier->d_name, buf);
	file = (t_fil *)malloc(sizeof(t_fil));
	file->size = buf->st_size;
	file->name = fichier->d_name;
	t = time(&buf->st_mtimespec.tv_sec);
	file->date_m = ft_strdup(ctime(&t));
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
