/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pconin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 11:06:50 by pconin            #+#    #+#             */
/*   Updated: 2016/08/20 12:15:27 by pconin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H

# define FT_LS_H
# define STAT_HAVE_NSEC 1
# define BUFSIZE_LINK 1024
#define st_ctime st_ctim.tv_sec

#include <dirent.h>
#include <unistd.h>
#include "libft.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pwd.h>
#include <uuid/uuid.h>
#include <grp.h>

typedef struct		s_fil
{
	char			*path;
	char			typ;
	long long		time_s;
	long			nanotime;
	int				hide;
	char			*rgh;
	char			*name;
	char			*date_m;
	long long		size;
	struct s_fil	*next;
	char			*us_name;
	char			*gr_name;
	int				links;
	int				bloc;
	char			*link;
	float			maj;
	float			min;
}					t_fil;

typedef struct		s_mem
{
	int				one;
	int				l;
	int				R;
	int				a;
	int				r;
	char			**files;
	int				nb_file;
	void			(*f_sort)(t_fil **head, t_fil *new);
}					t_mem;


//date.c
void	get_date(t_fil *file, time_t second, long nano);
//dir .c
int		my_opendir(const char *path, DIR **rep);
int		my_closedir(const char *path, DIR **rep);
//flags.c
void	flag_r(t_fil **begin_list);
int		size_list(t_fil *begin_list);
void	insert_list(t_fil **begin_list, t_fil *maillon, t_fil **newlist, int bool);
int		ft_timecmp(t_fil *cur, t_fil *new);
void	tri_ascii(t_fil **head, t_fil *new);
void	tri_date(t_fil **head, t_fil *new);
//init.c
void	ft_error(char *str);
void	init_arg(t_mem *s);
void	check_flag(t_mem *s, char c);
void	ft_add_arg(t_mem *s, char **argv, int i, int bool);
void	parse_arg(char **argv, t_mem *s);
//main.c
void	ls_rec(t_mem *s, char *path);
void	parse_for_rec(t_mem *s, t_fil *file);
void	ft_add_file(t_mem *s, struct dirent *fichier, char *name, t_fil **list);
//print.c
void	print_l(t_fil *file);
void	total_blocks(t_fil *file, t_mem *s);
void	ft_print_path(char *path);
void	ft_print_link(t_fil *file);
void	print_dir(t_fil *file, t_mem *s, char *path, int bool);
//rights.c
int		get_link(t_fil *f, char *path);
void	get_type(t_fil *f, struct stat buf);
void	get_rights(t_fil *f, struct stat buf);


#endif

