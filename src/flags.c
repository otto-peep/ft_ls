/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pconin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/03 11:22:33 by pconin            #+#    #+#             */
/*   Updated: 2016/08/18 16:10:02 by pconin           ###   ########.fr       */
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

void	tri_ascii(t_fil **head, t_fil *new)
{
	t_fil	*maillon;
	t_fil	*pre;

	maillon = *head;
	pre = NULL;
	if (ft_strcmp(mem->name, new->name) > 0)
		insert_list(head, NULL, &new)
	else
	{
		while (maillon->next)
		{
			if (ft_strcmp(maillon->name, new->name) > 0)
			{
				insert_list(&maillon, pre, &new);
				return;
			}
			pre = maillon;
			maillon = maillon->next;
		}
		if (ft_strcmp(maillon->name, new->name) > 0)
			insert_list(&maillon, pre, &new);
		else
			maillon->next = new;
	}
}


void	tri_date(t_fil **head, t_fil *new)
{
	t_fil	*maillon;
	t_fil	*pre;

	maillon = *head;
	pre = NULL;
	if (maillon->time_s <=)
		insert_list(head, NULL, &new)
	else
	{
		while (maillon->next)
		{
			if (ft_strcmp(maillon->name, new->name) > 0)
			{
				insert_list(&maillon, pre, &new);
				return;
			}
			pre = maillon;
			maillon = maillon->next;
		}
		if (ft_strcmp(maillon->name, new->name) > 0)
			insert_list(&maillon, pre, &new);
		else
			maillon->next = new;
	}
}

void	ft_flags(t_fil **begin_list, t_mem *s)
{
	*begin_list = tri_ascii(begin_list);
	if (s->t == 1)
		*begin_list = tri_date(begin_list);
	if (s->r == 1)
		flag_r(begin_list);
}
