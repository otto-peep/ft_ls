/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstdel.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pconin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/21 20:00:19 by pconin            #+#    #+#             */
/*   Updated: 2016/08/21 20:11:14 by pconin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	lstdel(t_fil *list, t_mem *s)
{
	t_fil *mem;
	while (list->next)
	{
		mem = list;
		list = list->next;
		free(mem->path);
		free(mem->rgh);
		free(mem->name);
		free(mem->date_m);
		free(mem->us_name);
		free(mem->gr_name);
		if (mem->link)
			free(mem->link);
	}
}
