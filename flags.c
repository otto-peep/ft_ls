/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pconin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/03 11:22:33 by pconin            #+#    #+#             */
/*   Updated: 2016/05/03 13:16:46 by pconin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	flag_r(t_fil **begin_list)
{
	t_fil	*prev;
	t_fil	*current;
	t_fil	*next;

	prev = NULL;
	current = *begin_list;
	while (current != NULL)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	*begin_list = prev;
}

void	tri_ascii(t_fil **begin_list)
{
	t_fil	*current;
	t_fil	*first;
	t_fil	*mem;

	mem = NULL;
	first = NULL;
	current = *begin_list;
	while (current != NULL)
	{
		if (current->name[0] > current->next->name[0])
		{
			first = current->next;
			mem = first->next;
			first->next = current;
			current->next = mem;
			tri_ascii(begin_list);
			break ;
		}
		else
			current = current->next;
	}
	return ;
}

void	ft_flags(t_fil **begin_list, t_mem *s)
{
	if (s->r == 1)
		flag_r(begin_list);
}
