/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   date.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pconin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/03 10:22:37 by pconin            #+#    #+#             */
/*   Updated: 2016/05/03 11:56:11 by pconin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	get_date(t_fil *file, long filetime)
{
	char **tab;

	file->time_s = filetime;
	tab = ft_strsplit(ctime(&filetime), ' ');
	if (((int)time - (int)filetime) > 15778800 
			&& ((int)time - (int)filetime) < -15778800)
	{
		file->date_m = ft_strdup(tab[1]);
		file->date_m = ft_strjoin(file->date_m, " ");
		file->date_m = ft_strjoin(file->date_m, tab[2]);
		file->date_m = ft_strjoin(file->date_m, " ");
		file->date_m = ft_strjoin(file->date_m, tab[4]);
	}
	else
	{
		file->date_m = ft_strdup(tab[1]);
		file->date_m = ft_strjoin(file->date_m, " ");
		file->date_m = ft_strjoin(file->date_m, tab[2]);
		file->date_m = ft_strjoin(file->date_m, " ");
		file->date_m = ft_strjoin(file->date_m, ft_strsub(tab[3], 0, (ft_strlen(tab[3]) - 3)));
	}
}
