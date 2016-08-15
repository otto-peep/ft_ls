/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   date.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pconin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/03 10:22:37 by pconin            #+#    #+#             */
/*   Updated: 2016/08/15 14:43:22 by pconin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	get_date(t_fil *file, time_t second, long nano)
{
	char	**tab;
	time_t	date;

	file->time_s = second;
	file->nanotime = nano;
	tab = ft_strsplit(ctime(&second), ' ');
	date = time(&date) - second;
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
		file->date_m = ft_strjoin(file->date_m, ft_strsub(tab[3], 0, (ft_strlen(tab[3]) - 3)));
	}
//	free(tab);
}
