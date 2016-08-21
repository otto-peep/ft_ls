/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstdel.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pconin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/21 20:00:19 by pconin            #+#    #+#             */
/*   Updated: 2016/08/21 21:51:53 by pconin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		size_list(t_fil *begin_list)
{
	int	count;

	count = 0;
	while (begin_list->next)
	{
		count++;
		begin_list = begin_list->next;
	}
	return (count);
}

void	lstdel(t_fil *list, t_mem *s)
{
	t_fil *mem;

	while (list->next)
	{
		mem = list;
		list = list->next;
		ft_strdel(&mem->path);
		ft_strdel(&mem->rgh);
		ft_strdel(&mem->name);
		ft_strdel(&mem->date_m);
		ft_strdel(&mem->us_name);
		ft_strdel(&mem->gr_name);
		if (mem->link)
			ft_strdel(&mem->link);
	}
}
