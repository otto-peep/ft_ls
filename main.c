/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pconin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 11:33:06 by pconin            #+#    #+#             */
/*   Updated: 2016/04/26 15:18:26 by pconin           ###   ########.fr       */
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

int		main(int argc, char **argv)
{
	t_mem *s;

	s = (t_mem *)malloc(sizeof(t_mem));
	if (argc < 2)
		exit(0);
	parse_arg(argv, s);
	
	DIR* rep = NULL;
	struct dirent	*Fichier = NULL;
	struct stat *buf;

	buf = malloc(sizeof(struct stat));
	rep = opendir(s->arg);
	if (rep == NULL)
		perror("error");
	while ((Fichier = readdir(rep)) != NULL)
	{
		stat(Fichier->d_name, buf);
		printf("%lld \n", buf->st_size);
	}
	return (0);
}
