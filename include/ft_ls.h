/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pconin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 11:06:50 by pconin            #+#    #+#             */
/*   Updated: 2016/08/24 18:36:42 by pconin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H

# define FT_LS_H
# define STAT_HAVE_NSEC 1
# define BUFSIZE_LINK 1024

# include <dirent.h>
# include <unistd.h>
# include "../libft/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# include <pwd.h>
# include <uuid/uuid.h>
# include <grp.h>

typedef struct		s_fil
{
	size_t			inode;
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
	char			*oldpath;
	int				only;
	char			u;
	int				o;
	int				n;
	int				i;
	int				f;
	int				t;
	int				s;
	int				one;
	int				l;
	int				rec;
	int				a;
	int				r;
	char			**files;
	int				nb_file;
	void			(*f_sort)(t_fil **head, t_fil *new);
}					t_mem;

void				get_date(t_fil *file, struct stat buf, t_mem *s);
int					my_opendir(char *path, DIR **rep, t_mem *s);
int					my_closedir(const char *path, DIR **rep);
void				wrong_flag(char c);
void				flag_r(t_fil **begin_list);
int					size_list(t_fil *begin_list);
void				insert_list(t_fil
						**begin, t_fil *maillon, t_fil **newlist, int bool);
int					ft_timecmp(t_fil *cur, t_fil *new);
void				tri_ascii(t_fil **head, t_fil *new);
void				tri_date(t_fil **head, t_fil *new);
void				ft_error(char *str);
void				init_arg(t_mem *s);
void				check_flag(t_mem *s, char c);
void				ft_add_arg(t_mem *s, char **argv, int i, int bool);
void				parse_arg(char **argv, t_mem *s);
void				ls_rec(t_mem *s, char *path);
void				parse_for_rec(t_mem *s, t_fil *file);
void				ft_add_file(t_mem *s,
						struct dirent *fichier, char *name, t_fil **list);
void				print_l(t_fil *file, t_mem *s);
void				total_blocks(t_fil *file, t_mem *s);
void				ft_print_path(char *path);
void				ft_print_link(t_fil *file);
void				print_dir(t_fil *file, t_mem *s, char *path, int bool);
int					get_link(t_fil *f, char *path);
void				get_type(t_fil *f, struct stat buf);
void				get_rights(t_fil *f, struct stat buf);
void				get_usgr(t_fil *file, t_mem *s, struct stat buf);
void				lstdel(t_fil *list);
void				tri_size(t_fil **head, t_fil *new);
void				no_sort(t_fil **head, t_fil *new);
void				ft_priority(t_mem *s);
int					ft_extract(t_fil **list, char *str);
#endif
