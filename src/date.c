/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   date.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pconin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/03 10:22:37 by pconin            #+#    #+#             */
/*   Updated: 2016/08/23 17:36:01 by pconin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	get_date2(t_fil *file, char **tab, time_t date)
{
	if ((date > 15778800) || (date < -15778800))
	{
		file->date_m = ft_strdup(tab[1]);
		file->date_m = ft_strjoin(file->date_m, "  ");
		file->date_m = ft_strjoin(file->date_m, tab[2]);
		file->date_m = ft_strjoin(file->date_m, "  ");
		file->date_m = ft_strjoin(file->date_m, ft_strsub(tab[4], 0, 4));
	}
	else
	{
		file->date_m = ft_strdup(tab[1]);
		file->date_m = ft_strjoin(file->date_m, "  ");
		file->date_m = ft_strjoin(file->date_m, tab[2]);
		file->date_m = ft_strjoin(file->date_m, "  ");
		file->date_m = ft_strjoin(file->date_m,
				ft_strsub(tab[3], 0, (ft_strlen(tab[3]) - 3)));
	}
}

void	get_date(t_fil *file, struct stat buf, t_mem *s)
{
	char	**tab;
	time_t	date;

	if (s->u == 'x')
	{
		file->time_s = buf.st_mtimespec.tv_sec;
		file->nanotime = buf.st_mtimespec.tv_nsec;
	}
	else if (s->u == 'U')
	{
		file->time_s = buf.st_birthtimespec.tv_sec;
		file->nanotime = buf.st_birthtimespec.tv_nsec;
	}
	else if (s->u == 'u')
	{
		file->time_s = buf.st_atimespec.tv_sec;
		file->nanotime = buf.st_atimespec.tv_nsec;
	}
	tab = ft_strsplit(ctime((time_t*)&file->time_s), ' ');
	date = time(&date) - file->time_s;
	get_date2(file, tab, date);
}
