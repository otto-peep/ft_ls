/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pconin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/03 11:22:33 by pconin            #+#    #+#             */
/*   Updated: 2016/05/13 19:28:01 by pconin           ###   ########.fr       */
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

void	push_front(t_fil **tmp, t_fil ***begin_list, t_fil **maillon, t_fil ***newlist)
{
	*tmp = **begin_list;
	**begin_list = (**begin_list)->next;
	(*tmp)->next = *maillon;
	**newlist = *tmp;
}

void	push_back(t_fil **tmp, t_fil ***begin_list, t_fil **maillon, t_fil ***newlist)
{
	*tmp = **begin_list;
	**begin_list = (**begin_list)->next;
	(*tmp)->next = NULL;
	(*maillon)->next = *tmp;
}

void	insert_list(t_fil **tmp, t_fil ***begin_list, t_fil **maillon, t_fil ***newlist)
{
	*tmp = **newlist;
	while ((*tmp)->next != *maillon && (*tmp)->next)
		*tmp = (*tmp)->next;
	(*tmp)->next = **begin_list;
	*tmp = (*tmp)->next;
	**begin_list = (**begin_list)->next;
	(*tmp)->next = *maillon;
}

t_fil	*tri_ascii(t_fil **begin_list)
{
	t_fil	**newlist;
	t_fil	*maillon;
	t_fil	*tmp;

	newlist = malloc(sizeof(t_fil *) * size_list(*begin_list));
	init_tri(newlist, begin_list);
	while (*begin_list)
	{
		maillon = *newlist;
		if (ft_strcmp((*begin_list)->name, maillon->name) > 0)
			push_front(&tmp, &begin_list, &maillon, &newlist);
		else
		{
			while (ft_strcmp((*begin_list)->name, maillon->name) <= 0 && maillon->next)
				maillon = maillon->next;
			if (maillon->next == NULL)
				push_back(&tmp, &begin_list, &maillon, &newlist);
			else
				insert_list(&tmp, &begin_list, &maillon, &newlist);
		}
	}

	return (*newlist);
}

t_fil	*tri_date(t_fil **begin_list)
{
	t_fil	**newlist;
	t_fil	*maillon;
	t_fil	*tmp;

	newlist = malloc(sizeof(t_fil *) * size_list(*begin_list));
	init_tri(newlist, begin_list);
	while (*begin_list)
	{
		maillon = *newlist;
		if ((*begin_list)->time_s > maillon->time_s)
			push_front(&tmp, &begin_list, &maillon, &newlist);
		else
		{
			while ((*begin_list)->time_s <= maillon->time_s && maillon->next)
				maillon = maillon->next;
			if (maillon->next == NULL)
				push_back(&tmp, &begin_list, &maillon, &newlist);
			else
				insert_list(&tmp, &begin_list, &maillon, &newlist);
		}
	}
	return (*newlist);
}

void	ft_flags(t_fil **begin_list, t_mem *s)
{
	if (s->t == 1)
		*begin_list = tri_date(begin_list);
	else
		*begin_list = tri_ascii(begin_list);
	if (s->r == 0)
		flag_r(begin_list);
}
