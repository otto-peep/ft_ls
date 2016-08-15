/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pconin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 11:06:50 by pconin            #+#    #+#             */
/*   Updated: 2016/08/15 17:06:53 by pconin           ###   ########.fr       */
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

typedef struct		s_mem
{
	int				l;
	int				R;
	int				a;
	int				r;
	int				t;
	char			**files;
	int				nb_file;
}					t_mem;

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

void	ft_error(char *str);
void	get_date(t_fil *file, time_t second, long nano);
void	get_rights(t_fil *f, struct stat buf);
void	get_type(t_fil *f, struct stat buf);
void	print_dir(t_fil *file, t_mem *s, char *path, int bool);
void	parse_arg(char **argv, t_mem *s);
void	ft_flags(t_fil **begin_list, t_mem *s);
//t_fil	*ft_fildup(t_fil *old);
void	ls_rec(t_mem *s, char *path);
int		get_link(t_fil *f, char *path);

#endif

