/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pconin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/03 11:22:33 by pconin            #+#    #+#             */
/*   Updated: 2016/08/15 17:10:32 by pconin           ###   ########.fr       */
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

int		size_list(t_fil *begin_list)
{
	int count;

	count = 0;
	while (begin_list->next)
	{
		count++;
		begin_list = begin_list->next;
	}
	return (count);
}

void	init_tri(t_fil **newlist, t_fil **oldlist)
{
	t_fil *tmp;

	tmp = *oldlist;
	*oldlist = (*oldlist)->next;
	tmp->next = NULL;
	*newlist = tmp;
}

void	push_front(t_fil ***begin_list, t_fil **maillon, t_fil ***newlist)
{
	t_fil *tmp;

	tmp = **begin_list;
	**begin_list = (**begin_list)->next;
	tmp->next = *maillon;
	**newlist = tmp;
}

void	push_back(t_fil ***begin_list, t_fil **maillon, t_fil ***newlist)
{
	t_fil *tmp;

	tmp = **begin_list;
	**begin_list = (**begin_list)->next;
	tmp->next = NULL;
	(*maillon)->next = tmp;
}

void	insert_list(t_fil ***begin_list, t_fil **maillon, t_fil ***newlist)
{
	t_fil *tmp;

	tmp = **newlist;
	while (tmp->next != *maillon && tmp->next)
		tmp = tmp->next;
	tmp->next = **begin_list;
	tmp = tmp->next;
	**begin_list = (**begin_list)->next;
	tmp->next = *maillon;
}

t_fil	*tri_ascii(t_fil **begin_list)
{
	t_fil	**newlist;
	t_fil	*maillon;
	int bool;

	bool = 0;
	newlist = malloc(sizeof(t_fil *) * size_list(*begin_list));
	init_tri(newlist, begin_list);
	while (*begin_list)
	{
		maillon = *newlist;
		if (ft_strcmp(maillon->name, (*begin_list)->name) > 0)
			push_front(&begin_list, &maillon, &newlist);
		else
		{
			while ((bool = (ft_strcmp(maillon->name, (*begin_list)->name))) <= 0 && maillon->next)
				maillon = maillon->next;
			if (bool > 0)
				insert_list(&begin_list, &maillon, &newlist);
			else
				push_back(&begin_list, &maillon, &newlist);
		}
	}
	return (*newlist);
}

t_fil	*tri_date(t_fil **begin_list)
{
	t_fil	**newlist;
	t_fil	*maillon;
	int		bool;
	int a = 49;
	bool = 0;
	newlist = malloc(sizeof(t_fil *) * size_list(*begin_list));
	init_tri(newlist, begin_list);
	while (*begin_list)
	{
		maillon = *newlist;
		if (maillon->time_s < (*begin_list)->time_s)
		{
			push_front(&begin_list, &maillon, &newlist);
		}
		else
		{
			while ((((bool = (maillon->time_s - (*begin_list)->time_s)) > 0 || (bool == 0 && maillon->nanotime >= (*begin_list)->nanotime)) && maillon->next) && a > 0)
				maillon = maillon->next;
		}
			if (bool <= 0)
				insert_list(&begin_list, &maillon, &newlist);
			else
				push_back(&begin_list, &maillon, &newlist);
	}
	return (*newlist);
}

void	ft_flags(t_fil **begin_list, t_mem *s)
{
	*begin_list = tri_ascii(begin_list);
	if (s->t == 1)
		*begin_list = tri_date(begin_list);
	if (s->r == 1)
		flag_r(begin_list);
}
